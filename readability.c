#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int count_letters(string words);
int count_words(string words);
int count_sentences(string words);
int main(void)
{
    string text = get_string("Text:\n");
    printf("%i letter(s)\n%i word(s)\n%i sentence(s)\n",count_letters(text),count_words(text),count_sentences(text));
    float index = 0.0588 * (((100*float)count_letters(text)/(float)(count_words(text))) - 0.296) * (((100*(float)count_words(text)/(float)(count_sentences(text))) - 15.8);
    printf("Grade Level: %f",index);

}
int count_letters(string words)
{
    int sum = 0;
    int i = 0;
      while(words[i]!='\0')
        {
        //if word's asckii for the letter is between lowercase and uppercase alphabet, add 1 to sum;
           if(isalpha(words[i]))
           {
              sum++;
           }
           i++;
        }
        return sum;
}
int count_words(string words)
{
    int sum2 = 0;
    int i = 0;
      while(words[i]!='\0')
        {
           if(isblank(words[i]))
           {
              sum2++;
           }
           i++;
        }
        return sum2+1;
}
int count_sentences(string words)
{
    int sum3 = 0;
    int i = 0;
      while(words[i]!='\0')
        {
           if(words[i]=='.'|| words[i]=='?'|| words[i]=='!')
           {
              sum3++;
           }
           i++;
        }
        return sum3;

}