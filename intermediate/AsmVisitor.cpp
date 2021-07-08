#include "AsmVisitor.h"

using namespace std;


antlrcpp::Any AsmVisitor::visitProgram(IntermediateParser::ProgramContext *ctx) {
    vector<string> output;
    auto statements = ctx->main()->statements;
    for (auto statement : statements) {
        auto intermediate_result = visitStatement(statement).as<vector<string>>();
        output.insert(output.end(), intermediate_result.begin(), intermediate_result.end());
    }

    return output;
}

antlrcpp::Any AsmVisitor::visitStatement(IntermediateParser::StatementContext *ctx) {
    vector<string> output;
    if (ctx->declaration()) {
        return visitDeclaration(ctx->declaration());
    }
    else if (ctx->assignment()) {
        return visitAssignment(ctx->assignment());
    }

    throw "Unrecognized statement";
}

antlrcpp::Any AsmVisitor::visitDeclaration(IntermediateParser::DeclarationContext *ctx) {
    vector<string> output;
    antlr4::Token* variable = ctx->id;
    if (variable) {
        auto next_register = get_next_register();
        auto next_address = get_next_address();
        if (next_register != -1) {
            m_registers_available[next_register] = false;
            m_symbols_table.insert({
                variable->getText(),
                { StorageType::Register, next_register }});
        }
        else if (next_address != -1) {
            m_addresses_available[next_address] = false;
            m_symbols_table.insert({
                variable->getText(),
                { StorageType::Memory, next_address }});
        }
        else {
            throw "Out of memory.";
        }
    }
    
    return output;
}

antlrcpp::Any AsmVisitor::visitAssignment(IntermediateParser::AssignmentContext *ctx) {
    vector<string> output;
    auto expression = ctx->expr;
    auto expression_output = visitExpression(expression).as<vector<string>>();
    // assumes that the result of the expression is stored in R0
    output.insert(output.end(), expression_output.begin(), expression_output.end());
    auto variable_location = m_symbols_table.at(ctx->id->getText());

    store_variable(variable_location, 0, output);

    return output;
}

antlrcpp::Any AsmVisitor::visitExpression(IntermediateParser::ExpressionContext *ctx) {
    vector<string> output;
    if (ctx->binary_operator()) {
        auto binary_operator = ctx->binary_operator()->getText();
        auto op1 = ctx->op1;
        load_operand(op1, 0, output);

        auto op2 = ctx->op2;
        load_operand(op2, 1, output);

        if (binary_operator == "+") {
            output.push_back("ADD r0 r1 r0");
        }
        else if (binary_operator == "-") {
            output.push_back("SUB r0 r1 r0");
        }
        else if (binary_operator == "&") {
            output.push_back("AND r0 r1 r0");
        }
        else if (binary_operator == "|") {
            output.push_back("OR r0 r1 r0");
        }
    }
    else if (ctx->unary_operator()) {
        auto unary_operator = ctx->unary_operator()->getText();
        if (unary_operator == "!") {
            auto op1 = ctx->op1;
            load_operand(op1, 0, output);
            output.push_back("NOT r0 r0");
        }
    }
    else {
        auto value = ctx->op1;
        load_operand(value, 0, output);
    }

    return output;
}

int AsmVisitor::get_next_register() {
    for (unsigned long i = 0; i < m_registers_available.size(); ++i) {
        if (m_registers_available[i]) return i;
    }

    return -1;
}


int AsmVisitor::get_next_address() {
    for (unsigned long i = 0; i < m_addresses_available.size(); ++i) {
        if (m_addresses_available[i]) return i;
    }

    return -1;
}

void AsmVisitor::load_variable(std::pair<StorageType, int> location, int targetRegister, vector<string>& output) {
    if (location.first ==  StorageType::Register) {
        // store the result in a register
        output.push_back(string("MOV r") + to_string(targetRegister) + " r" + to_string(location.second));
    }
    else if (location.first == StorageType::Memory) {
        // store the result in memory
        output.push_back(string("LOAD r") + to_string(targetRegister) + " " + to_string(location.second));
    }
}

void AsmVisitor::store_variable(std::pair<StorageType, int> location, int targetRegister, vector<string>& output) {
    if (location.first ==  StorageType::Register) {
        // store the result in a register
        output.push_back(string("MOV r") + to_string(location.second) + " r" + to_string(targetRegister));
    }
    else if (location.first == StorageType::Memory) {
        // store the result in memory
        output.push_back(string("STORE r") + to_string(targetRegister) + " " + to_string(location.second));
    }
}

void AsmVisitor::load_immediate(int immediate, int targetRegister, vector<string>& output) {
    output.push_back(string("LOADI r") + to_string(targetRegister) + " " + to_string(immediate));
}

void AsmVisitor::load_operand(IntermediateParser::ValueContext* op, int targetRegister, vector<string>& output) {
    if (op->variable()) {
        auto var_name = op->variable()->ID()->getText();
        auto first_operand_location = m_symbols_table.at(var_name);
        load_variable(first_operand_location, targetRegister, output);
    }
    else {
        auto constant = op->constant()->NUM()->getText();
        load_immediate(std::atoi(constant.c_str()), targetRegister, output);
    }
}


std::map<std::string, std::pair<StorageType, int>> AsmVisitor::get_symbols() {
    return m_symbols_table;
}
