#include <iostream>
using namespace std;
int length(const char *s)
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {
    }
    return i;
}
void changeCase(char A[])
{
    for(int i=0;A[i]!='\0';i++)
    {
        if(!(A[i]>=65 && A[i]<=90))
            A[i]=A[i]-32;
    }
}
void vowelsAndConsonent(char A[])       // itna memmory kaise accept karega isliye will accept pointer to array
{
    int vowels=0;
    for(int i=0;A[i]!='\0';i++)
    {
        if(A[i]=='A'||A[i]=='a'||A[i]=='E'||A[i]=='e'||A[i]=='I'||A[i]=='i'||A[i]=='O'||A[i]=='o'||A[i]=='U'||A[i]=='u')
        {
            ++vowels;
        }
    }
    cout<<"vowels = "<<vowels;
    cout<<"\nConsonent = "<<length(A)-vowels;
}
int validate(const char C[])
//The warning means that your function does not modify the data pointed at by C and so the function could
// be better declared with pointer to 'const' parameter.
{
    for(int i=0;C[i]!='\0';i++)
        if(!(C[i]>=65 && C[i]<=90) || !(C[i]>=97 && C[i]<=122) || !(C[i]>=48 && C[i]<=57))
        {
            return 0;
        }
    return 1;
}
void reverse(char b[])
{
    int j=length(b)-1;
    char temp;
    for(int i=0;i<j;j--,i++)
    {
        temp=b[i];
        b[i]=b[j];
        b[j]=temp;
    }
}
void compare(const char A[],const char B[])        // jahan original data modify nahi horaha wahan const pointer use karo
{
    int i,j;
    for(i=0,j=0;A[i]!='\0'&& B[j]!='\0';i++,j++)
    {
        if(A[i]!=B[i])
            break;
    }
    if(A[i]==B[j])              //compairing '\0'--->Null value---->Ascii code=0
        cout<<"Equal";
    else if(A[i]<B[i])
        cout<<"Smaller";
    else cout<<"Greater";
}
void palindrome(const char P[])
{
    int j=length(P)-1,i;
    for(i=0;i<j;i++,j--)
    {
        if(P[i]!=P[j])
        {
            cout<<"Not a Palimdrome";
            break;
        }
    }
    if(i==j)
        cout<<"Is a palimdrome";
}
void duplicates(const char A[])                    //with hashing
{
    int H[26],i;
    for(i=0;i<26;i++)
    {
        H[i]=0;
    }
    for(i=0;A[i]!='\0';i++)
    {
        H[A[i]-97]++;           //storing 'a' occurance at H[0]
    }
    for(i=0;i<26;i++)
    {
        if(H[i]>1)
            cout<<char(i+97)<<" is repeated "<<H[i]<<" times";
    }
}
void duplicatesMM(const char A[])               // easy theory in notebook
{
    int H=0;
    int X;
    for(int i=0;A[i]!='\0';i++)
    {
        X=1;
        X=X << (A[i]-97);
        if((X & H) > 0)                            // -->masking
            cout<<"Duplicate is "<<A[i];
        else H = (X | H);                           //  -->merging
    }
}
void anagram(const char A[],const char B[])
{
    int H[26]={0},i;
    for(i=0;A[i]!='\0';i++)
    {
        H[A[i]-97]++;
    }
    for(i=0;B[i]!='\0';i++)
    {
        H[B[i]-97]--;
        if(H[B[i]-97]<0)
        {
            cout<<"not anagram";
            break;
        }
    }
    if(B[i]=='\0')
        cout<<"it is anagram";
}
void permutation(char S[],int k)
{
    static int A[10]={0};
    static char Res[10];
    int i;
    if(S[k]=='\0')
        cout<<"\n"<<Res;
    else{
        for(i=0;S[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                Res[k]=S[i];
                A[i]=1;
                permutation(S,k+1);
                A[i]=0;
            }
        }
    }
}
void swapA(char *L,char *I)
{
    char temp;
    temp=*L;
    *L=*I;
    *I=temp;
}
void permutationAlter(char S[],int l,int h)
{
    int i;
    if(l==h)
        cout<<"\n\n\n\n\n"<<S;
    else
    {
        for(i=l;i<=h;i++)
        {
            swapA(&S[l],&S[i]);
            permutationAlter(S,l+1,h);
            swapA(&S[l],&S[i]);
        }
    }
}
int main() {
    int ch;
    for(;;)
    {
        cout<<"1.Length\n";
        cout<<"2.ChangeCase\n";
        cout<<"3.VowelsAndConsonents\n";
        cout<<"4.Validate\n";
        cout<<"5.Reverse\n";
        cout<<"6.Compare\n";
        cout<<"7.Palindrome\n";
        cout<<"8.Duplicates\n";
        cout<<"9.Duplicates with Merging and Masking\n";
        cout<<"10.Anagram\n";
        cout<<"11.Permutation\n";
        cout<<"12.Different Method of Permutation";
        cout<<"\n\nEnter choice: ";
        cin>>ch;
        switch(ch){
            case 1: {   char s[]="WElcOme";                  // actually not allowed in c++11
                length(s);
                break;}
            case 2: {char A[]="WElcoMEanikEt";           // cout<<A<<s   ---> gives right answer
                changeCase(A);                         //A means address of first element of array
                break;}

            case 3: {char C[]="WElcoMEanikEt";
                vowelsAndConsonent(C);                  // chalta hai attitude  char c[10];   cin>>c;
                break;}
            case 4:{char D[]="A12!HGF";
                if(validate(D))
                    cout<<"true";
                else cout<<"false";
                break;}               // WITHOUT BRACES;
                     //variable will cause a "crosses initialization" error, because it is possible to skip the initialization of Variable,
                                     //but after that it will still be in scope, even though it was never created in the first place.
                                  //WITH BRACES
                                    //because the variable is inside a block, and will die at the end of the block
                                    // ( at the closing { ), so after that it will not be in scope in any case.
            case 5:{char E[]="PYTHON";
                        reverse(E);
                        break;}

            case 6: {char F[]="check";
                    char G[]="Check";
                      compare(F,G);
                      break;}

            case 7:{char H[]="madam";
                palindrome(H);
                break;}

            case 8:{char I[]="hippopotomous";
                duplicates(I);              // all in upper or lower case
                break;}

            case 9: {char J[]="hippopotomous";
                duplicatesMM(J);              // never use Such inputs it signifies string instead
                break;}

            case 10: {char K[]="decimal";
                    char L[]="medical";
                anagram(K,L);           // make char Array[]="Something"   and then pass Array
                break;}

            case 11:{char p[]="ABC";
                permutation("ABC",0);
                break;}

            case 12:{char P[]="ABC";
                permutationAlter(P,0,2);
                break;}

                case 13:exit(0);

            default: cout<<"Invalid choice";
        }
    }
    return 0;
}