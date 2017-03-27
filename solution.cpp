#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>

using namespace std;

char strRelation[] =
"A B 同学 同事 同乡\n"
"C D 同乡\n"
"E F 同学\n"
"G H 同姓\n"
"I J 同事\n"
"H I 同学 同乡\n"
"B J 同乡\n";

bool IsRelationSpace(const char * H1, const char * H2, int DimensionDistance)
{
    string name1(H1);
    string name2(H2);
    //cout << name1 << " " << name2 << endl;
      
    return false;
}
int main(int argc, char* argv[])
{   
    //for(int i=0; i<10; ++i) cout << strRelation[i] << endl;
    cout << strRelation << endl;
    int i=0;
    while(strRelation[i] != '0'){
        if(!(strRelation[i] & 0x80)){
            cout << "english case" << endl;
        } else {
            cout << "chinese case" << endl;
        }
        ++i;
    }
	char name1[100] = "";
	char name2[100] = "";
	int RelationDistance = 0;
	std::cin >> name1 >> name2 >> RelationDistance;
	bool bRet = IsRelationSpace(name1, name2, RelationDistance);

	printf("true");
	//printf("false");

	return 0;
}
