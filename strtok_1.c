#include "shell.h"

/**
 * mystr_twords - Convert a string into an array of theWord using delimiters.
 * @string: The input string to be split into theWord.
 * @delimiters: The delimiters used to split the string into theWord (optional).
 *
 * Return: Array of strings representing the theWord, or NULL if no theWord found
 */

char **mystr_twords(char *string, char *delimiters)
{
	int i, j, k, m, wordsNumber = 0;
	char **theWord;

	if (string == NULL || string[0] == 0)
		return (NULL);
	if (!delimiters)
		delimiters = " ";
	for (i = 0; string[i] != '\0'; i++) /*Count the number of theWord in string*/
		if (!is_delimeter(string[i], delimiters) &&
			(is_delimeter(string[i + 1], delimiters) ||
			 !string[i + 1]))
			wordsNumber++;

	if (wordsNumber == 0)
		return (NULL);
	theWord = malloc((1 + wordsNumber) * sizeof(char *)); /*Alloc memry for arr*/
	if (!theWord)
		return (NULL);
	for (i = 0, j = 0; j < wordsNumber; j++) /* Split the string into theWord */
	{
		while (is_delimeter(string[i], delimiters)) /* Skip delimiters */
			i++;
		k = 0; /* Count the number of characters in the word */
		while (!is_delimeter(string[i + k], delimiters) && string[i + k])
			k++;
		theWord[j] = malloc((k + 1) * sizeof(char)); /*Alloc memory for word*/
		if (!theWord[j])
		{ /* Free all previously allocated memory */
			for (k = 0; k < j; k++)
				free(theWord[k]);
			free(theWord);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			theWord[j][m] = string[i++]; /* Copy the word into the array */
		theWord[j][m] = 0;
	}
	theWord[j] = NULL; /* Set the last element of the array to NULL */
	return (theWord);
}
