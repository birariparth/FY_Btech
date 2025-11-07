#include <stdio.h>
#include <string.h>

// Function to get string length
int getStringLength(char str[])
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

// Function to copy string
void copyString(char source[], char destination[])
{
    int i = 0;
    while (source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

// Function to compare two strings
int stringCompare(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0;  // Strings are not the same
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

// Function to concatenate strings
void concatenateStrings(char str1[], char str2[])
{
    int i = 0, j = 0;
    while (str1[i] != '\0')
        i++;
    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

// Function to highlight occurrences of a word in the document
void highlightWord(char document[], char word[])
{
    int docLen = getStringLength(document);
    int wordLen = getStringLength(word);
    char highlighted[6000];
    int highlightedIndex = 0;
   
    for (int i = 0; i < docLen;)
    {
        int j = 0;
        while (j < wordLen && document[i + j] == word[j])
        {
            j++;
        }

        if (j == wordLen)
        {
            highlighted[highlightedIndex++] = '{';
            for (int k = 0; k < wordLen; k++)
            {
                highlighted[highlightedIndex++] = document[i + k];
            }
            highlighted[highlightedIndex++] = '}';
            i += wordLen;
        }
        else
        {
            highlighted[highlightedIndex++] = document[i++];
        }
    }

    highlighted[highlightedIndex] = '\0';
    strcpy(document, highlighted);
}

// Function to count how many times a word appears in document
int stringSearch(char document[], char word[])
{
    int docLen = getStringLength(document);
    int wordLen = getStringLength(word);
    int count = 0;

    for (int i = 0; i <= docLen - wordLen; i++)
    {
        int j = 0;
        while (j < wordLen && document[i + j] == word[j])
        {
            j++;
        }
        if (j == wordLen) {
            count++;
        }
    }
    return count;
}

int main()
{
    char document[5000], word1[100], word2[100];

    printf("Enter the document text (max 5000 characters):\n");
    fgets(document, sizeof(document), stdin);
    document[getStringLength(document) - 1] = '\0';

    printf("Enter the first word:\n");
    fgets(word1, sizeof(word1), stdin);
    word1[getStringLength(word1) - 1] = '\0';

    printf("Enter the second word:\n");
    fgets(word2, sizeof(word2), stdin);
    word2[getStringLength(word2) - 1] = '\0';
   
    int wordLength1 = getStringLength(word1);
    printf("\nLength of search word %s: %d\n", word1, wordLength1);
   
    int wordLength2 = getStringLength(word2);
    printf("\nLength of search word %s: %d\n", word2, wordLength2);
   
    char result[200];

    if (stringCompare(word1, word2))
    {
        printf("\nBoth words are SAME.\n");

        int count = stringSearch(document, word1);
        printf("The word '%s' appears %d times in the document.\n", word1, count);

        highlightWord(document, word1);
       
        if (count > 0)
        {
            if (count == 1)
                snprintf(result, sizeof(result), "----- %s found 1 time", word1);
            else
                snprintf(result, sizeof(result), "----- %s found %d times", word1, count);
        }
        else
        {
            snprintf(result, sizeof(result), "----- %s not found", word1);
        }
        concatenateStrings(document, result);
        printf("\nHighlighted Document:\n%s\n", document);
    }
    else
    {
        printf("\nBoth words are DIFFERENT.\n");

        int count1 = stringSearch(document, word1);
        int count2 = stringSearch(document, word2);

        printf("The word '%s' appears %d times.\n", word1, count1);
        printf("The word '%s' appears %d times.\n", word2, count2);

        // Highlight both words (word1 first, then word2)
        highlightWord(document, word1);
        highlightWord(document, word2);
       
        if (count1 > 0&& count2 > 0)
        {
        if (count1 == 1 && count2 == 1)
            snprintf(result, sizeof(result), "----- %s & %s found 1 time", word1,word2);
        else
            snprintf(result, sizeof(result), "----- %s found %d times & %s found %d times", word1, count1, word2,count2);
        }
        else if(count1 > 0 && count2 == 0)
        {
            snprintf(result, sizeof(result), "----- %s is found %d times & %s is not found", word1, count1, word2);
        }
        else if(count1 == 0 && count2 > 0)
        {
            snprintf(result, sizeof(result), "----- %s not is found & %s is found %d times", word1, word2, count2);
        }
        else
        {
            snprintf(result, sizeof(result), "----- %s not found & %s not found", word1, word2);
        }
       
        concatenateStrings(document, result);
        printf("\nHighlighted Document:\n%s\n", document);
    }

    return 0;
}