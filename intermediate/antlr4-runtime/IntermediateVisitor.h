
// Generated from Intermediate.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "IntermediateParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by IntermediateParser.
 */
class  IntermediateVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by IntermediateParser.
   */
    virtual antlrcpp::Any visitProgram(IntermediateParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitMain(IntermediateParser::MainContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(IntermediateParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(IntermediateParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitStatement(IntermediateParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitBinary_operator(IntermediateParser::Binary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitUnary_operator(IntermediateParser::Unary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitValue(IntermediateParser::ValueContext *context) = 0;

    virtual antlrcpp::Any visitVariable(IntermediateParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitConstant(IntermediateParser::ConstantContext *context) = 0;

    virtual antlrcpp::Any visitExpression(IntermediateParser::ExpressionContext *context) = 0;


};

