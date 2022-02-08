/**
 * @file scanner.cpp
 * @author <a href="mailto:a.hakimnejad@mrl-spl.ir">Amirhossein Hakimnejad</a>
 *
 * @date 2018 Nov
 */


#include "scanner.hpp"
#include <iomanip>
#include <iostream>
#include <cctype>
#include <iostream>
#include <fstream>


using namespace std;
using std::cout;
using std::vector;
using std::cerr;
using std::endl;
using std::ofstream;



// tableMaker
struct TableFormat {
    int width;
    char fill;
    TableFormat(): width(14), fill(' ') {}
    template<typename T>
    TableFormat& operator<<(const T& data) {
        std::cout << data << std::setw(width) << std::setfill(fill);
        return *this;
    }
    TableFormat& operator<<(std::ostream&(*out)(std::ostream&)) {
        std::cout << out;
        return *this;
    }
};



bool isID(const std::string &str)
{
  if(std::isdigit(str[0]))
    return false;
  
  //if str[0] is a special symbol then return false
   //if(!(isalpha(str[0])))
    //return false;


  int counter = 0;
  if(str[0] == '_')
    counter++;

  for(; counter < str.size(); counter++)
    if(!(isalnum(str[counter])))
      return false;

  return true;
}

bool isComment(const std::string &str)
{
  return str == "/*" || str == "//";
}

bool isDigit(const std::string &str)
{
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool isString(const std::string &str)
{
  return str[0] == '"' && str[str.size()-1] == '"';
}

bool isStringSingle(const std::string &str)
{
  return str[0] == '\'' && str[str.size()-1] == '\'';
}


bool isStringParenthesis(const std::string &str)
{
  return ((str[1] == '"' && str[str.size()-2] == '"')&& ( str[0] == '(' &&  str[str.size()-1] == ')')) ;
}

bool isStringParenthesisSingle(const std::string &str)
{
  return str[1] == '\'' && str[str.size()-2] == '\'' && str[0] == '(' &&  str[str.size()-1] == ')' ;
}



bool isBool(const std::string &str)
{
  return str == "true" || str == "false";
}

// call is string here
bool isLiteral(const std::string &str)
{
//  return isDigit(str) || isString(str) || isStringSingle(str) || isStringParenthesis || isBool(str);
return isDigit(str) || isString(str) || isBool(str) ||  isStringSingle(str) || isStringParenthesis(str) || isStringParenthesisSingle(str)  ;
}


bool isKeyword(const std::string &str)
{
  const vector<std::string> keywords{"bool", "char", "default", "double", "drop", "else", "float", "high", "if", "inp", "int", "low", "out", "pow", "term", "until"};
  for(const auto& keyword : keywords)
    if (keyword == str)
      return true;

  return false;
}


//isKeywordNoiseWords
bool isKeywordNoiseWords(const std::string &str)
{
  const vector<std::string> keywords{"input", "integer", "output", "power"};
  for(const auto& keyword : keywords)
    if (keyword == str)
      return true;

  return false;
}


//isKeywordReserved
bool isKeywordReserved(const std::string &str)
{
  const vector<std::string> keywords{"body", "invalid", "next", "valid"};
  for(const auto& keyword : keywords)
    if (keyword == str)
      return true;

  return false;
}





bool isStatement(const std::string &str)
{
  const vector<std::string> statements{"for", "while"};
  for(const auto& statement : statements)
    if (statement == str)
      return true;

  return false;
}

//RelationalOperators
bool isOperator(const std::string &str)
{
  const vector<std::string> operators{"==", ">", "<", ">=", "<=",  "!=", "+", "-", "!", "/", "%", "*"};
  //const vector<std::string> operators{"<", ">", "<=", ">=",  "==", "!="};
  for(const auto& op : operators)
    if (op == str)
      return true;

  return false;
}

//ArithmeticOperators
bool isOperatorArithmetic(const std::string &str)
{
  const vector<std::string> operators{"+","-","/","*","%","++","--"};
  for(const auto& op : operators)
    if (op == str)
      return true;

  return false;
}
//AssignmentOperators
bool isOperatorAssignment(const std::string &str)
{
  const vector<std::string> operators{"=", "-=", "*=", "+=", "/=", "%="};
  for(const auto& op : operators)
    if (op == str)
      return true;

  return false;
}

//LogicalOperators
bool isOperatorLogical(const std::string &str)
{
  const vector<std::string> operators{"!", "&&", "||"};
  for(const auto& op : operators)
    if (op == str)
      return true;

  return false;
}



bool isSeparator(const std::string &str)
{
  const vector<std::string> Separators{"{", "}", ",", "(", ")", ";", "[", "]"};
  for(const auto& separate : Separators)
    if (separate == str)
      return true;

  return false;
}

bool isNotLegal(const std::string &str)
{
  return str == " " || str == "\n";
}

void printRoleOfToken(const std::string& token)
{
TableFormat out;
out.width = 8;
ofstream outdatav2;
 
if(isOperatorArithmetic(token)){
    out << "Operators - Arithmetic:  " << token << " ";
    outdatav2.open("SymbolTable.txt", std::ios_base::app);
    outdatav2 << "Operators - Arithmetic:  " << token << " "  << endl ;
    outdatav2.close();
    std::cout << "\n";
   }

	
  else if(isOperator(token)){
    out << "Operators - Relational:  " << token << " ";
    outdatav2.open("SymbolTable.txt", std::ios_base::app);
    outdatav2 << "Operators - Relational:  " << token << " "  << endl ;
   outdatav2.close();
    std::cout << "\n";
	}
	
 
   
  else if(isOperatorAssignment(token)){
    out << "Operators - Assignment:  " << token << " ";
    outdatav2.open("SymbolTable.txt", std::ios_base::app);
    outdatav2 << "Operators - Assignment:  " << token << " "  << endl ;
    outdatav2.close();
    std::cout << "\n";
   }
   
   
  else if(isOperatorLogical(token)){
    out << "Operators - Logical:   " << token << " ";
    outdatav2.open("SymbolTable.txt", std::ios_base::app);
    outdatav2 << "Operators - Logical:  " << token << " "  << endl ;
    outdatav2.close();
    std::cout << "\n";
   }
   
  else if(isSeparator(token)){
    out << "Delimeters:   \t\t" << token << " ";
    outdatav2.open("SymbolTable.txt", std::ios_base::app);
    outdatav2 << "Delimeters: \t\t " << token << " "  << endl ;
    outdatav2.close(); 
   std::cout << "\n";
   }

  //isKeyword	
  else if(isKeyword(token)){
    out << "Keywords:   \t\t" << token << " ";
    outdatav2.open("SymbolTable.txt", std::ios_base::app);
    outdatav2 << "Keywords:  \t\t" << token << " " <<  endl ;
    outdatav2.close();
    std::cout << "\n";
	}
	

	
  //isKeywordReserved	
  else if(isKeywordReserved(token)){
    out << "Reserved Keywords:   \t\t" << token << " ";
    outdatav2.open("SymbolTable.txt", std::ios_base::app);
    outdatav2 << "Reserved Keywords:  \t" << token << " "  << endl ;
    outdatav2.close();
    std::cout << "\n";
	}
	
  //isKeywordNoiseWords
  else if(isKeywordNoiseWords(token)){
    out << "NoiseWords Keywords:   \t\t" << token << " ";
    outdatav2.open("SymbolTable.txt", std::ios_base::app);
    outdatav2 << "NoiseWords Keywords: \t" << token << " "  << endl ;
    outdatav2.close();
    std::cout << "\n";
	}
	

  else if(isID(token)){
    out << "Identifiers:   \t\t" << token << " ";
    outdatav2.open("SymbolTable.txt", std::ios_base::app);
    outdatav2 << "Identifiers:  \t\t" << token << " "  << endl ;
    outdatav2.close();
    std::cout << "\n";
        }


	
  else if(isLiteral(token)){
    out << "Literals:   \t\t" << token << " ";
    outdatav2.open("SymbolTable.txt", std::ios_base::app);
    outdatav2 << "Literals:  \t\t" << token << " "  << endl ;
    outdatav2.close();	
    std::cout << "\n";
	}


	
  else if(isComment(token)){
    out << "Comments:   \t\t" << token << " ";
    outdatav2.open("SymbolTable.txt", std::ios_base::app);
    outdatav2 << "Comments:  \t\t" << token << " "  << endl ;
    outdatav2.close();
   std::cout << "\n";
	}


	
  else
    throw std::runtime_error("Invalid token: " + token);
} //end of printRoleOfToken


void lexicalAnalyze(const std::string &nameOfFile)
{
  char ch;
  std::string buffer;
  std::fstream file(nameOfFile, std::fstream::in);

  if (!file.is_open())
  {
    cout << "error while opening the file\n";
    exit(0);
  }

  bool miltiCm = false, singleCm = false;
  while (file >> std::noskipws >> ch)
  {
    if(singleCm || miltiCm)
    {
      if(singleCm && ch == '\n')
        singleCm = false;

      if(miltiCm && ch == '*')
      {
        file >> ch;
        if(ch == EOF)
          break;

        if(ch == '/')
          miltiCm = false;
      }
      continue;
    }

    if(ch == '/')
    {
      std::string comm(1, ch);
      file >> ch;
      if(ch == EOF)
      {
        printRoleOfToken(comm);
        break;
      }

      if(ch == '*')
      {
        miltiCm = true;
        comm += ch;
      }
      else if(ch == '/')
      {
        singleCm = true;
        comm += ch;
      }
      if(miltiCm || singleCm)
      {
        printRoleOfToken(comm);
        continue;
      }
    }

    if(isNotLegal(std::string(1, ch)))
    {
      if(!buffer.empty())
      {
        printRoleOfToken(buffer);
        buffer = "";
      }
      continue;
    }

    if(isOperatorArithmetic(std::string(1, ch)) && !isOperatorArithmetic(buffer))
    {
      if(!buffer.empty())
      {
        printRoleOfToken(buffer);
        buffer = "";
      }
    }



    if(!isOperatorArithmetic(std::string(1, ch)) && isOperatorArithmetic(buffer))
    {
      printRoleOfToken(buffer);
      buffer = "";
    }

    if(isSeparator(std::string(1, ch)))
    {
      if(!buffer.empty())
      {
        printRoleOfToken(buffer);
        buffer = "";
      }
      if(isSeparator(std::string(1, ch)))
      {
        printRoleOfToken(std::string(1, ch));
        continue;
      }
    }
    buffer += ch;
  }
  file.close();
}
