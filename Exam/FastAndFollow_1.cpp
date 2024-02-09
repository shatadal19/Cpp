#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

// Here is first function
void First_Func(char, int, int);
int count, n = 0;

//Here is follow function
void Follw_func(char, int, int);
void follow(char c);

// For stroing annul result of first function
char StoreFirst[10][100];

// For stroing annul result of first function
char Store_follow [10][100];
int m = 0;

// Stores the Production rules
char Pro[10][10];
char f[10], first[10];
int k;
char ck;
int e;

int main()
{
    int jm = 0;
    int km = 0;
    int i, choice;
    char c, ch;
    count = 8;

    strcpy(Pro[0], "E=TR");
    strcpy(Pro[1], "R=+TR");
    strcpy(Pro[2], "R=#");
    strcpy(Pro[3], "T=FY");
    strcpy(Pro[4], "Y=*FY");
    strcpy(Pro[5], "Y=#");
    strcpy(Pro[6], "F=(E)");
    strcpy(Pro[7], "F=i");

    int kay;
    char done[count];
    int ptr = -1;

    // Initializing the StoreFirst array
    for(k = 0; k < count; k++) {
        for(kay = 0; kay < 100; kay++) {
            StoreFirst[k][kay] = '!';
        }
    }
    int point1 = 0, point2, x;

    for(k = 0; k < count; k++)
    {
        c = Pro[k][0];
        point2 = 0;
        x = 0;

        // Checking if First of c has
        // already been calculated
        for(kay = 0; kay <= ptr; kay++)
            if(c == done[kay])
                x = 1;

        if (x == 1)
            continue;

        // Function call
        First_Func(c, 0, 0);
        ptr += 1;

        // Adding c to the calculated list
        done[ptr] = c;
        cout << "\n First(" << c << ") = { ";
        StoreFirst[point1][point2++] = c;

        // Printing the First Sets of the grammar
        for(i = 0 + jm; i < n; i++) {
            int lark = 0, chk = 0;

            for(lark = 0; lark < point2; lark++) {

                if (first[i] == StoreFirst[point1][lark]) {
                    chk = 1;
                    break;
                }
            }
            if(chk == 0)
            {
                cout << first[i] << ", ";
                StoreFirst[point1][point2++] = first[i];
            }
        }
        cout << "}\n";
        jm = n;
        point1++;
    }
    cout << "\n";
    cout << "-----------------------------------------------\n\n";
    char donee[count];
    ptr = -1;

    // Initializing the Store_follow  array
    for(k = 0; k < count; k++) {
        for(kay = 0; kay < 100; kay++) {
            Store_follow [k][kay] = '!';
        }
    }
    point1 = 0;
    int land = 0;
    for(e = 0; e < count; e++)
    {
        ck = Pro[e][0];
        point2 = 0;
        x = 0;

        // Checking if Follow of ck
        // has already been calculated
        for(kay = 0; kay <= ptr; kay++)
            if(ck == donee[kay])
                x = 1;

        if (x == 1)
            continue;
        land += 1;

        // Function call
        follow(ck);
        ptr += 1;

        // Adding ck to the calculated list
        donee[ptr] = ck;
        if(ck=='$'){
            continue;
        }
        cout << " Follow(" << ck << ") = { ";
        Store_follow [point1][point2++] = ck;

        // Printing the Follow Sets of the grammar
        for(i = 0 + km; i < m; i++) {
            int lark = 0, chk = 0;
            for(lark = 0; lark < point2; lark++)
            {
                if (f[i] == Store_follow [point1][lark])
                {
                    chk = 1;
                    break;
                }
            }
            if(chk == 0)
            {
                cout << f[i] << ", ";
                Store_follow [point1][point2++] = f[i];
            }
        }
        cout << " }\n\n";
        km = m;
        point1++;
    }
}

void follow(char c)
{
    int i, j;

    // Adding "$" to the follow
    // set of the start symbol
    if(Pro[0][0] == c) {
        f[m++] = '$';
    }
    for(i = 0; i < 10; i++)
    {
        for(j = 2; j < 10; j++)
        {
            if(Pro[i][j] == c)
            {
                if(Pro[i][j+1] != '\0')
                {
                    // Calculate the first of the next
                    // Non-Terminal in the Pro
                    Follw_func(Pro[i][j+1], i, (j+2));
                }

                if(Pro[i][j+1]=='\0' && c!=Pro[i][0])
                {
                    // Calculate the follow of the Non-Terminal
                    // in the L.H.S. of the Pro
                    follow(Pro[i][0]);
                }
            }
        }
    }
}

void First_Func(char c, int q1, int q2)
{
    int j;

    // The case where we
    // encounter a Terminal
    if(!(isupper(c))) {
        first[n++] = c;
    }
    for(j = 0; j < count; j++)
    {
        if(Pro[j][0] == c)
        {
            if(Pro[j][2] == '#')
            {
                if(Pro[q1][q2] == '\0')
                    first[n++] = '#';
                else if(Pro[q1][q2] != '\0'
                        && (q1 != 0 || q2 != 0))
                {
                    // Recursion to calculate First of New
                    // Non-Terminal we encounter after epsilon
                    First_Func(Pro[q1][q2], q1, (q2+1));
                }
                else
                    first[n++] = '#';
            }
            else if(!isupper(Pro[j][2]))
            {
                first[n++] = Pro[j][2];
            }
            else
            {
                // Recursion to calculate First of
                // New Non-Terminal we encounter
                // at the beginning
                First_Func(Pro[j][2], j, 3);
            }
        }
    }
}

void Follw_func(char c, int c1, int c2)
{
    int k;

    // The case where we encounter
    // a Terminal
    if(!(isupper(c)))
        f[m++] = c;
    else
    {
        int i = 0, j = 1;
        for(i = 0; i < count; i++)
        {
            if(StoreFirst[i][0] == c)
                break;
        }

        //Including the First set of the
        // Non-Terminal in the Follow of
        // the original query
        while(StoreFirst[i][j] != '!')
        {
            if(StoreFirst[i][j] != '#')
            {
                f[m++] = StoreFirst[i][j];
            }
            else
            {
                if(Pro[c1][c2] == '\0')
                {
                    // Case where we reach the
                    // end of a Pro
                    follow(Pro[c1][0]);
                }
                else
                {
                    // Recursion to the next symbol
                    // in case we encounter a "#"
                    Follw_func(Pro[c1][c2], c1, c2+1);
                }
            }
            j++;
        }
    }
}