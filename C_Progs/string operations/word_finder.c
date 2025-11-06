#include <stdio.h>

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
            return 0;  // Strings are not same
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

// Function to count how many times word appears in document
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
        if (j == wordLen)
        {
            count++;
        }
    }
    return count; // return total matches
}

int main()
{
    char document[500], word[100];

    printf("Enter the document text (max 500 characters):\n");
    fgets(document, sizeof(document), stdin);
    document[getStringLength(document) - 1] = '\0';  // Remove newline

    printf("Enter the search word:\n");
    fgets(word, sizeof(word), stdin);
    word[getStringLength(word) - 1] = '\0';  // Remove newline

    int wordLength = getStringLength(word);
    printf("\nLength of search word: %d\n", wordLength);

    char copiedWord[100];
    copyString(word, copiedWord);
    printf("Copied word: %s\n", copiedWord);

    int count = stringSearch(document, word);

    // Prepare result message
    char result[200];
    if (count > 0)
    {
        if (count == 1)
            snprintf(result, sizeof(result), " %s found 1 time", word);
        else
            snprintf(result, sizeof(result), " %s found %d times", word, count);
    }
    else
    {
        snprintf(result, sizeof(result), " %s not found", word);
    }

    // Concatenate the result message to the document
    concatenateStrings(document, result);

    printf("\nUpdated Document: %s\n", document);

    return 0;
}
