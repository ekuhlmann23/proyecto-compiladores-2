#include "mainwindow.h"

#include <fstream>
#include <sstream>
#include <streambuf>
#include <string>
#include <vector>

extern "C" int yyparse(void);

#include "antlr4-runtime/antlr4-runtime.h"
#include "ui_mainwindow.h"
#include "intermediate/antlr4-runtime/IntermediateLexer.h"
#include "intermediate/antlr4-runtime/IntermediateParser.h"
#include "intermediate/AsmVisitor.h"
#include "binary/y.tab.h"
#include "binary/lex.yy.h"

using namespace antlr4;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_compile_clicked()
{
    // clear text boxes
    ui->txt_asm->setText("");
    ui->txt_bin->setText("");

    // clear files
    std::ofstream ofs;
    ofs.open("asm.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    ofs.open("binary.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    // set input file for yacc
    yyin = fopen("asm.txt", "r");

    // get cpp input
    auto plain_text = ui->txt_cpp->toPlainText();
    std::stringstream stream(plain_text.toStdString());

    ANTLRInputStream input(stream);
    IntermediateLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    IntermediateParser parser(&tokens);

    IntermediateParser::ProgramContext* tree = parser.program();

    AsmVisitor visitor;

    std::vector<std::string> output = visitor.visitProgram(tree).as<std::vector<std::string>>();
    std::string intermediate;

    // get ASM output
    for (const auto& line : output) {
        intermediate.append(line);
        intermediate.append("\n");
    }
    ui->txt_asm->setText(QString::fromStdString(intermediate));

    // write to intermediate file
    std::ofstream asmFile("asm.txt");
    asmFile << intermediate << std::endl;

    // get binary output
    yyparse();
    std::ifstream binaryOutputFile("binary.txt");
    std::string binary((std::istreambuf_iterator<char>(binaryOutputFile)),
                     std::istreambuf_iterator<char>());
    binaryOutputFile.close();
    ui->txt_bin->setText(QString::fromStdString(binary));


    // get symbols table
    auto symbols = visitor.get_symbols();
    ui->tab_symbols->clear();
    ui->tab_symbols->setRowCount(symbols.size());
    ui->tab_symbols->setColumnCount(2);
    ui->tab_symbols->setHorizontalHeaderItem(0, new QTableWidgetItem("Symbol"));
    ui->tab_symbols->setHorizontalHeaderItem(1, new QTableWidgetItem("Location"));
    int row = 0;
    for (const auto& pair : symbols) {
        QTableWidgetItem* symbol = new QTableWidgetItem(QString::fromStdString(pair.first));
        QTableWidgetItem* location;
        if (pair.second.first == StorageType::Register) {
            location = new QTableWidgetItem(QString::fromStdString("r" + std::to_string(pair.second.second)));
        }
        else {
            location = new QTableWidgetItem(QString::fromStdString(std::to_string(pair.second.second)));
        }
        ui->tab_symbols->setItem(row, 0, symbol);
        ui->tab_symbols->setItem(row, 1, location);
        row++;
    }
}

