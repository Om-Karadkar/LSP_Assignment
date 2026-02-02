#include <stdio.h>

int MyStrlen(const char *str)
{
    int length = 0;

    if(str == NULL)
    {
        return 0;
    }

    while(str[length] != '\0')
    {
        length++;
    }

    return length;
}

void MyStrcpy(char *dest, const char *src)
{
    int i = 0;

    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void MyStrncpy(char *dest, const char *src, int n)
{
    int i = 0;

    while(i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    while(i < n)
    {
        dest[i] = '\0';
        i++;
    }
}

void MyStrcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;

    while(dest[i] != '\0')
    {
        i++;
    }

    while(src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

int MyStrcmp(const char *str1, const char *str2)
{
    int i = 0;

    while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }

    return str1[i] - str2[i];
}

int MyStrncmp(const char *str1, const char *str2, int n)
{
    int i = 0;

    while(i < n && str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }

    if(i < n)
    {
        return str1[i] - str2[i];
    }

    return 0;
}

void MyStrrev(char *str)
{
    int start = 0;
    int end = 0;
    char temp;

    while(str[end] != '\0')
    {
        end++;
    }
    end--;

    while(start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char *MyStrchr(const char *str, char ch)
{
    int i = 0;

    while(str[i] != '\0')
    {
        if(str[i] == ch)
        {
            return (char *)&str[i];
        }
        i++;
    }

    return NULL;
}

char *MyStrstr(const char *str, const char *substr)
{
    int i = 0;
    int j = 0;
    int match = 0;

    while(str[i] != '\0')
    {
        j = 0;
        match = 1;

        while(substr[j] != '\0')
        {
            if(str[i + j] != substr[j])
            {
                match = 0;
                break;
            }
            j++;
        }

        if(match == 1)
        {
            return (char *)&str[i];
        }
        i++;
    }

    return NULL;
}
