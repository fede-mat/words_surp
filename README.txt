Categorical Data Analysis
This repository contains code for analyzing categorical data and constructing measures based on the frequency of occurrence of each letter in a certain position of a set of five letter words. The following are descriptions of the files and the process involved in constructing a measure from categorical data.

Code 1: calculate_surprisal.c
Description:
This code calculates the surprisal of each word contained in the file word_list.txt based on the frequency statistics of letters provided in the file frequency_stats.txt. Surprisal is a measure of how unexpected or surprising a particular word is based on the distribution of letters in the language.

Files:
calculate_surprisal.c: The main C code for calculating surprisal.
word_list.txt: Input file containing a list of words.
frequency_stats.txt: Input file containing frequency statistics of letters.
Process:
Read the list of words from word_list.txt.
Read the frequency statistics of letters from frequency_stats.txt.
Calculate the surprisal of each word based on the letter frequencies.
Output the calculated surprisal values into surprisal_output.txt.
Code 2: sort_words.c
Description:
This code sorts the words based on their surprisal values calculated in the previous step. Sorting the words allows us to analyze and interpret the data more effectively.

Files:
sort_words.c: The main C code for sorting words based on surprisal.
surprisal_output.txt: Input file containing the calculated surprisal values.
sorted_word_list.txt: Output file to store the sorted list of words.
Process:
Read the calculated surprisal values from surprisal_output.txt.
Sort the words based on their surprisal values.
Output the sorted list of words into sorted_word_list.txt.
Conclusion:
These codes provide a basic framework for analyzing categorical data and constructing measures such as surprisal. By understanding the frequency distribution of categories within a dataset, we can gain insights into the underlying patterns and associations present in the data.

