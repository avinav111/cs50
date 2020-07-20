#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    if(strlen(argv[1])!=26)
    {
        printf("Usage: ./substitution key");
        return 1;
    }

    string userinput = argv[1];
    char key [26];
    bool duplicate[26];
    for(int i = 0; i<26; i++)
    {
        duplicate[i]=false;
    }
    for(int i = 0; i<26; i++)
        {
            if(isalpha(key[i]))
            {
                if(isupper(key[i]))
                {
                    if(duplicate[key[i]-'A']==true)
                    {
                        printf ("Key must not contain duplicate letters: %c\n", duplicate[i]);
                        return 1;
                    }
                    else
                    {
                        duplicate[key[i]-'A']=true;
                        key[i] = duplicate[i] -'A';
                    }
                }
                else if(islower(key[i]))
                {
                    if(duplicate[key[i]-'a']==true)
                    {
                        printf ("Key must not contain duplicate letters: %c\n", duplicate[i]);
                        return 1;
                    }
                    else
                    {
                        duplicate[key[i]-'a']=true;
                        key[i] = duplicate[i] -'a';
                    }
                }
            }
            else
            {
                printf("Key must contain only alphabetical letters:\n");
                return 1;
            }
        }

    string plainText = get_string("plaintext: \n");
    string cipherText = plainText;
    for(int i = 0;i<strlen(plainText);i++)
    {
        if(isalpha(plainText))
        {
            if(isupper(plainText))
            {
                  cipherText[i]= (key[plainText[i]-'A']='A');
            }
            else if(islower(plainText))
            {
                  cipherText[i]= (key[plainText[i]-'a']='a');
            }
        }
        else
        {
           cipherText[i]=plainText[i]; //This allows non alphabetical characters to remain unchanged like spaces, punctuation, numbers, etc.
        }

    }
    printf("ciphertext: %s\n", cipherText);

    return 0;
}
/*bool validate(string letters)
{
    string alphabet = ("abcdefghijklmnopqrstuvwxyz");

    // loop that goes through alphabet and then another loop that goes through letters and then compare the two variables at the same place to make sure that
   //draft 1:  if(strlen(letters) == 26 && (isupper(letters) || islower(letters)) && isalpha(letters) + way to detect duplicates.
    return true;
}
*/