#Play-fair_Cipher

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	string str="TRXYCBMHAFCMUVYEOHPTCSAFCSSTEQCSINTYIMSTNAAFCSCEMRBHXAAVAFRMIUCQPUHLMRLCCETOTFNHMAKUXAHKOTAWANAOTXTFFUEISCWNAFHMEBFUMCVAUGTOTREBMHYLFIFUUVTYANEHBSEIQYOQMOUVSFAMEAFTEPYHYSXNSKEIFUSC";
	int len=str.size();
	cout<<str;
    string key="SECURITY";
	char keyarr[5][5]={'S','E','C','U','R','I','T','Y','A','B','D','F','G','H','K','L','M','N','O','P','Q','V','W','X','Z'};
    int m,f1,f2,s1,s2;
	for (m = 0; m < len; m+= 2) {
        char x=str[m],y=str[m+1];
        if (x == 'J')
            x = 'I';
        else if (y == 'J')
            y = 'I';

        for(int i =0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (keyarr[i][j] == x) {
                    f1 = i;
                    f2 = j;
                }
                else if(keyarr[i][j] == y) {
                    s1 = i;
                    s2 = j;
                }
            }
        }
		if (f1 == s1) {
			str[m] = keyarr[f1][(f2 +4)%5];
			str[m + 1] = keyarr[f1][(s2 +4)%5];
		}
		else if (f2 == s2) {
			str[m] = keyarr[(f1+4)%5][f2];
			str[m + 1] = keyarr[(s1 +4)%5][f2];
		}
		else {
			str[m] = keyarr[f1][s2];
			str[m + 1] = keyarr[s1][f2];
		}
	}
	cout<<"\n",
	cout<<str;

	return 0;
}