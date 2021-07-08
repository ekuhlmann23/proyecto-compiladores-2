
// Generated from Intermediate.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "IntermediateVisitor.h"


/**
 * This class provides an empty implementation of IntermediateVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  IntermediateBaseVisitor : public IntermediateVisitor {
public:

  virtual antlrcpp::Any visitProgram(IntermediateParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMain(IntermediateParser::MainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(IntermediateParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(IntermediateParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(IntermediateParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinary_operator(IntermediateParser::Binary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_operator(IntermediateParser::Unary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue(IntermediateParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(IntermediateParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant(IntermediateParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(IntermediateParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }


};

