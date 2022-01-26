## CodeForces Solutions

vs-code user snippet

```
{
	// read https://code.visualstudio.com/docs/editor/userdefinedsnippets for details
	"Print to console": {
		"prefix": "cpp",
		"body": [
			"#include <iostream>",
			"#include <algorithm>",
			"#include <cstring>",
			"",
			"// Created by Simonhancrew on $CURRENT_YEAR/$CURRENT_MONTH/$CURRENT_DATE",
			"",
			"using namespace std;",
			"",
			"typedef long long LL;",
			"typedef pair<int,int> PII;",
			"#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)",
			"",
			"const int INF = 0x3f3f3f3f;",
			"",
			"int main(){",
			"    //#define _DEBUG",
			"    #ifdef _DEBUG",
			"        freopen(\"input.txt\",\"r\",stdin);",
			"        //freopen(\"output.txt\",\"w\",stdout);",
			"    #endif",
			"    fast_cin();",
			"    $0",
			"",
			"",
			"    return 0;",
			"}",
		],
		"description": "for cpp template"
	}
}
```

working on the construct algorithm now

form 800 to 3500,1100 in total.