%{
#include "string.tab.h"
%}



%%

0       { return ZERO; }
1       { return ONE; }
\n      { return END; }
.       { /* ignore anything else */ }

%%

int yywrap(){ return 1;}
