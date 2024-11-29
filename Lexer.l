%{
#include <iostream>
#include <string>
#include <unordered_map>
using std::cout;
using std::string;
using std::unordered_map;
%}

%option noyywrap
%x COMMENT

%%
"/*"          BEGIN(COMMENT);  
<COMMENT>.*   ;
<COMMENT>"*/" BEGIN(INITIAL);
%%

