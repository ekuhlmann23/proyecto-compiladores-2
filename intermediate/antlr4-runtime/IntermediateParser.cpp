
// Generated from Intermediate.g4 by ANTLR 4.7.2


#include "IntermediateVisitor.h"

#include "IntermediateParser.h"


using namespace antlrcpp;
using namespace antlr4;

IntermediateParser::IntermediateParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

IntermediateParser::~IntermediateParser() {
  delete _interpreter;
}

std::string IntermediateParser::getGrammarFileName() const {
  return "Intermediate.g4";
}

const std::vector<std::string>& IntermediateParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& IntermediateParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

IntermediateParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IntermediateParser::MainContext* IntermediateParser::ProgramContext::main() {
  return getRuleContext<IntermediateParser::MainContext>(0);
}

tree::TerminalNode* IntermediateParser::ProgramContext::EOF() {
  return getToken(IntermediateParser::EOF, 0);
}


size_t IntermediateParser::ProgramContext::getRuleIndex() const {
  return IntermediateParser::RuleProgram;
}

antlrcpp::Any IntermediateParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IntermediateVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

IntermediateParser::ProgramContext* IntermediateParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, IntermediateParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(22);
    main();
    setState(23);
    match(IntermediateParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainContext ------------------------------------------------------------------

IntermediateParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IntermediateParser::MainContext::INT() {
  return getToken(IntermediateParser::INT, 0);
}

tree::TerminalNode* IntermediateParser::MainContext::MAIN() {
  return getToken(IntermediateParser::MAIN, 0);
}

tree::TerminalNode* IntermediateParser::MainContext::OPAREN() {
  return getToken(IntermediateParser::OPAREN, 0);
}

tree::TerminalNode* IntermediateParser::MainContext::CPAREN() {
  return getToken(IntermediateParser::CPAREN, 0);
}

tree::TerminalNode* IntermediateParser::MainContext::OBRACE() {
  return getToken(IntermediateParser::OBRACE, 0);
}

tree::TerminalNode* IntermediateParser::MainContext::RETURN() {
  return getToken(IntermediateParser::RETURN, 0);
}

tree::TerminalNode* IntermediateParser::MainContext::SEMICOLON() {
  return getToken(IntermediateParser::SEMICOLON, 0);
}

tree::TerminalNode* IntermediateParser::MainContext::CBRACE() {
  return getToken(IntermediateParser::CBRACE, 0);
}

std::vector<IntermediateParser::StatementContext *> IntermediateParser::MainContext::statement() {
  return getRuleContexts<IntermediateParser::StatementContext>();
}

IntermediateParser::StatementContext* IntermediateParser::MainContext::statement(size_t i) {
  return getRuleContext<IntermediateParser::StatementContext>(i);
}


size_t IntermediateParser::MainContext::getRuleIndex() const {
  return IntermediateParser::RuleMain;
}

antlrcpp::Any IntermediateParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IntermediateVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

IntermediateParser::MainContext* IntermediateParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 2, IntermediateParser::RuleMain);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(25);
    match(IntermediateParser::INT);
    setState(26);
    match(IntermediateParser::MAIN);
    setState(27);
    match(IntermediateParser::OPAREN);
    setState(28);
    match(IntermediateParser::CPAREN);
    setState(29);
    match(IntermediateParser::OBRACE);
    setState(33);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IntermediateParser::INT

    || _la == IntermediateParser::ID) {
      setState(30);
      dynamic_cast<MainContext *>(_localctx)->statementContext = statement();
      dynamic_cast<MainContext *>(_localctx)->statements.push_back(dynamic_cast<MainContext *>(_localctx)->statementContext);
      setState(35);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(36);
    match(IntermediateParser::RETURN);
    setState(37);
    match(IntermediateParser::T__0);
    setState(38);
    match(IntermediateParser::SEMICOLON);
    setState(39);
    match(IntermediateParser::CBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

IntermediateParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IntermediateParser::DeclarationContext::INT() {
  return getToken(IntermediateParser::INT, 0);
}

tree::TerminalNode* IntermediateParser::DeclarationContext::SEMICOLON() {
  return getToken(IntermediateParser::SEMICOLON, 0);
}

tree::TerminalNode* IntermediateParser::DeclarationContext::ID() {
  return getToken(IntermediateParser::ID, 0);
}


size_t IntermediateParser::DeclarationContext::getRuleIndex() const {
  return IntermediateParser::RuleDeclaration;
}

antlrcpp::Any IntermediateParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IntermediateVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

IntermediateParser::DeclarationContext* IntermediateParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, IntermediateParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41);
    match(IntermediateParser::INT);
    setState(42);
    dynamic_cast<DeclarationContext *>(_localctx)->id = match(IntermediateParser::ID);
    setState(43);
    match(IntermediateParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

IntermediateParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IntermediateParser::AssignmentContext::SEMICOLON() {
  return getToken(IntermediateParser::SEMICOLON, 0);
}

tree::TerminalNode* IntermediateParser::AssignmentContext::ID() {
  return getToken(IntermediateParser::ID, 0);
}

IntermediateParser::ExpressionContext* IntermediateParser::AssignmentContext::expression() {
  return getRuleContext<IntermediateParser::ExpressionContext>(0);
}


size_t IntermediateParser::AssignmentContext::getRuleIndex() const {
  return IntermediateParser::RuleAssignment;
}

antlrcpp::Any IntermediateParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IntermediateVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

IntermediateParser::AssignmentContext* IntermediateParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 6, IntermediateParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    dynamic_cast<AssignmentContext *>(_localctx)->id = match(IntermediateParser::ID);
    setState(46);
    match(IntermediateParser::T__1);
    setState(47);
    dynamic_cast<AssignmentContext *>(_localctx)->expr = expression();
    setState(48);
    match(IntermediateParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

IntermediateParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IntermediateParser::AssignmentContext* IntermediateParser::StatementContext::assignment() {
  return getRuleContext<IntermediateParser::AssignmentContext>(0);
}

IntermediateParser::DeclarationContext* IntermediateParser::StatementContext::declaration() {
  return getRuleContext<IntermediateParser::DeclarationContext>(0);
}


size_t IntermediateParser::StatementContext::getRuleIndex() const {
  return IntermediateParser::RuleStatement;
}

antlrcpp::Any IntermediateParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IntermediateVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

IntermediateParser::StatementContext* IntermediateParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 8, IntermediateParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(52);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IntermediateParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(50);
        assignment();
        break;
      }

      case IntermediateParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(51);
        declaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binary_operatorContext ------------------------------------------------------------------

IntermediateParser::Binary_operatorContext::Binary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t IntermediateParser::Binary_operatorContext::getRuleIndex() const {
  return IntermediateParser::RuleBinary_operator;
}

antlrcpp::Any IntermediateParser::Binary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IntermediateVisitor*>(visitor))
    return parserVisitor->visitBinary_operator(this);
  else
    return visitor->visitChildren(this);
}

IntermediateParser::Binary_operatorContext* IntermediateParser::binary_operator() {
  Binary_operatorContext *_localctx = _tracker.createInstance<Binary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 10, IntermediateParser::RuleBinary_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << IntermediateParser::T__2)
      | (1ULL << IntermediateParser::T__3)
      | (1ULL << IntermediateParser::T__4)
      | (1ULL << IntermediateParser::T__5))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_operatorContext ------------------------------------------------------------------

IntermediateParser::Unary_operatorContext::Unary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t IntermediateParser::Unary_operatorContext::getRuleIndex() const {
  return IntermediateParser::RuleUnary_operator;
}

antlrcpp::Any IntermediateParser::Unary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IntermediateVisitor*>(visitor))
    return parserVisitor->visitUnary_operator(this);
  else
    return visitor->visitChildren(this);
}

IntermediateParser::Unary_operatorContext* IntermediateParser::unary_operator() {
  Unary_operatorContext *_localctx = _tracker.createInstance<Unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 12, IntermediateParser::RuleUnary_operator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(IntermediateParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

IntermediateParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IntermediateParser::VariableContext* IntermediateParser::ValueContext::variable() {
  return getRuleContext<IntermediateParser::VariableContext>(0);
}

IntermediateParser::ConstantContext* IntermediateParser::ValueContext::constant() {
  return getRuleContext<IntermediateParser::ConstantContext>(0);
}


size_t IntermediateParser::ValueContext::getRuleIndex() const {
  return IntermediateParser::RuleValue;
}

antlrcpp::Any IntermediateParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IntermediateVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

IntermediateParser::ValueContext* IntermediateParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 14, IntermediateParser::RuleValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(60);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IntermediateParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(58);
        variable();
        break;
      }

      case IntermediateParser::NUM: {
        enterOuterAlt(_localctx, 2);
        setState(59);
        constant();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

IntermediateParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IntermediateParser::VariableContext::ID() {
  return getToken(IntermediateParser::ID, 0);
}


size_t IntermediateParser::VariableContext::getRuleIndex() const {
  return IntermediateParser::RuleVariable;
}

antlrcpp::Any IntermediateParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IntermediateVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

IntermediateParser::VariableContext* IntermediateParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 16, IntermediateParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    match(IntermediateParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

IntermediateParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IntermediateParser::ConstantContext::NUM() {
  return getToken(IntermediateParser::NUM, 0);
}


size_t IntermediateParser::ConstantContext::getRuleIndex() const {
  return IntermediateParser::RuleConstant;
}

antlrcpp::Any IntermediateParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IntermediateVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

IntermediateParser::ConstantContext* IntermediateParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 18, IntermediateParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(IntermediateParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

IntermediateParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IntermediateParser::ValueContext *> IntermediateParser::ExpressionContext::value() {
  return getRuleContexts<IntermediateParser::ValueContext>();
}

IntermediateParser::ValueContext* IntermediateParser::ExpressionContext::value(size_t i) {
  return getRuleContext<IntermediateParser::ValueContext>(i);
}

IntermediateParser::Binary_operatorContext* IntermediateParser::ExpressionContext::binary_operator() {
  return getRuleContext<IntermediateParser::Binary_operatorContext>(0);
}

IntermediateParser::Unary_operatorContext* IntermediateParser::ExpressionContext::unary_operator() {
  return getRuleContext<IntermediateParser::Unary_operatorContext>(0);
}


size_t IntermediateParser::ExpressionContext::getRuleIndex() const {
  return IntermediateParser::RuleExpression;
}

antlrcpp::Any IntermediateParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IntermediateVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

IntermediateParser::ExpressionContext* IntermediateParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 20, IntermediateParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(74);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(66);
      dynamic_cast<ExpressionContext *>(_localctx)->op1 = value();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(67);
      dynamic_cast<ExpressionContext *>(_localctx)->op1 = value();
      setState(68);
      binary_operator();
      setState(69);
      dynamic_cast<ExpressionContext *>(_localctx)->op2 = value();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(71);
      unary_operator();
      setState(72);
      dynamic_cast<ExpressionContext *>(_localctx)->op1 = value();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> IntermediateParser::_decisionToDFA;
atn::PredictionContextCache IntermediateParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN IntermediateParser::_atn;
std::vector<uint16_t> IntermediateParser::_serializedATN;

std::vector<std::string> IntermediateParser::_ruleNames = {
  "program", "main", "declaration", "assignment", "statement", "binary_operator", 
  "unary_operator", "value", "variable", "constant", "expression"
};

std::vector<std::string> IntermediateParser::_literalNames = {
  "", "'0'", "'='", "'+'", "'-'", "'&'", "'|'", "'!'", "'int'", "'main'", 
  "'return'", "'('", "')'", "'{'", "'}'", "';'"
};

std::vector<std::string> IntermediateParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "INT", "MAIN", "RETURN", "OPAREN", "CPAREN", 
  "OBRACE", "CBRACE", "SEMICOLON", "ID", "NUM", "WS"
};

dfa::Vocabulary IntermediateParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> IntermediateParser::_tokenNames;

IntermediateParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x14, 0x4f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x22, 0xa, 0x3, 
    0xc, 0x3, 0xe, 0x3, 0x25, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x37, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x5, 0x9, 0x3f, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x5, 0xc, 0x4d, 0xa, 0xc, 0x3, 0xc, 0x2, 0x2, 0xd, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x2, 0x3, 0x3, 0x2, 0x5, 
    0x8, 0x2, 0x48, 0x2, 0x18, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x36, 0x3, 0x2, 0x2, 0x2, 0xc, 0x38, 0x3, 0x2, 0x2, 0x2, 0xe, 0x3a, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x12, 0x40, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x42, 0x3, 0x2, 0x2, 0x2, 0x16, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x19, 0x5, 0x4, 0x3, 0x2, 0x19, 0x1a, 0x7, 0x2, 0x2, 
    0x3, 0x1a, 0x3, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x7, 0xa, 0x2, 0x2, 
    0x1c, 0x1d, 0x7, 0xb, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0xd, 0x2, 0x2, 0x1e, 
    0x1f, 0x7, 0xe, 0x2, 0x2, 0x1f, 0x23, 0x7, 0xf, 0x2, 0x2, 0x20, 0x22, 
    0x5, 0xa, 0x6, 0x2, 0x21, 0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 0x25, 0x3, 
    0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 
    0x2, 0x2, 0x24, 0x26, 0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x27, 0x7, 0xc, 0x2, 0x2, 0x27, 0x28, 0x7, 0x3, 0x2, 0x2, 
    0x28, 0x29, 0x7, 0x11, 0x2, 0x2, 0x29, 0x2a, 0x7, 0x10, 0x2, 0x2, 0x2a, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0xa, 0x2, 0x2, 0x2c, 0x2d, 
    0x7, 0x12, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x11, 0x2, 0x2, 0x2e, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x12, 0x2, 0x2, 0x30, 0x31, 0x7, 0x4, 
    0x2, 0x2, 0x31, 0x32, 0x5, 0x16, 0xc, 0x2, 0x32, 0x33, 0x7, 0x11, 0x2, 
    0x2, 0x33, 0x9, 0x3, 0x2, 0x2, 0x2, 0x34, 0x37, 0x5, 0x8, 0x5, 0x2, 
    0x35, 0x37, 0x5, 0x6, 0x4, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 0xb, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 
    0x9, 0x2, 0x2, 0x2, 0x39, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x7, 
    0x9, 0x2, 0x2, 0x3b, 0xf, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3f, 0x5, 0x12, 
    0xa, 0x2, 0x3d, 0x3f, 0x5, 0x14, 0xb, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x41, 0x7, 0x12, 0x2, 0x2, 0x41, 0x13, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x43, 0x7, 0x13, 0x2, 0x2, 0x43, 0x15, 0x3, 0x2, 0x2, 0x2, 0x44, 0x4d, 
    0x5, 0x10, 0x9, 0x2, 0x45, 0x46, 0x5, 0x10, 0x9, 0x2, 0x46, 0x47, 0x5, 
    0xc, 0x7, 0x2, 0x47, 0x48, 0x5, 0x10, 0x9, 0x2, 0x48, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x49, 0x4a, 0x5, 0xe, 0x8, 0x2, 0x4a, 0x4b, 0x5, 0x10, 0x9, 
    0x2, 0x4b, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x44, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x45, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4d, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x6, 0x23, 0x36, 0x3e, 0x4c, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

IntermediateParser::Initializer IntermediateParser::_init;
