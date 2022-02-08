/**
 * @file scanner.hpp
 * @author <a href="mailto:a.hakimnejad@mrl-spl.ir">Amirhossein Hakimnejad</a>
 *
 * @date 2018 Nov
 */


#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using std::cout;
using std::vector;

bool isID(const std::string &str);
bool isComment(const std::string &str);
bool isDigit(const std::string &str);
bool isString(const std::string &str);
bool isBool(const std::string &str);
bool isLiteral(const std::string &str);
bool isKeyword(const std::string &str);
bool isKeywordReserved(const std::string &str);
bool isKeywordNoiseWords(const std::string &str);

bool isStatement(const std::string &str);
bool isOperator(const std::string &str);
bool isOperatorArithmetic(const std::string &str);
bool isOperatorLogical(const std::string &str);
bool isOperatorAssignment(const std::string &str);

bool isSeprator(const std::string &str);
bool isNotLegal(const std::string &str);
void printRoleOfToken(const vector<std::string>& tokens);
void lexicalAnalyze(const std::string &nameOfFile);
