#pragma once

#include <string>
#include "antlr4-runtime.h"
#include <array>
#include <map>
#include <string>
#include <utility>
#include "antlr4-runtime/IntermediateBaseVisitor.h"

enum StorageType {
    Register,
    Memory
};

class AsmVisitor : IntermediateBaseVisitor {
private:
    static constexpr int s_num_registers = 16;
    static const int s_num_addresses = 16;
    std::map<std::string, std::pair<StorageType, int>> m_symbols_table;
    std::array<bool, s_num_registers> m_registers_available;
    std::array<bool, s_num_addresses> m_addresses_available;

    int get_next_register();
    int get_next_address();
    void load_variable(std::pair<StorageType, int> location, int targetRegister, std::vector<std::string>& output);
    void store_variable(std::pair<StorageType, int> location, int targetRegister, std::vector<std::string>& output);
    void load_immediate(int immediate, int targetRegister, std::vector<std::string>& output);
    void load_operand(IntermediateParser::ValueContext* op, int targetRegister, std::vector<std::string>& output);

public:
    AsmVisitor() {
        // first 2 registers are reserved
        m_registers_available[0] = false;
        m_registers_available[1] = false;
    }

    std::map<std::string, std::pair<StorageType, int>> get_symbols();

    antlrcpp::Any visitProgram(IntermediateParser::ProgramContext *ctx);

    antlrcpp::Any visitExpression(IntermediateParser::ExpressionContext *ctx);	

    antlrcpp::Any visitStatement(IntermediateParser::StatementContext *ctx);

    antlrcpp::Any visitDeclaration(IntermediateParser::DeclarationContext *ctx);

    antlrcpp::Any visitAssignment(IntermediateParser::AssignmentContext *ctx);
};

