WORDLE GAME AID.

This repository contains the codes needed to construct the empirical measure of how common a 5-letter word is depending on the frequency of each letter in each position to aid in the resolution of the game 'Wordle'. 

Intuitively I've used a frequentist approach to probability where the sample mean is used as an estimator to infer properties of the population from a sample of data.

The file ''tutte le parole della lingua inglese.txt'' contains all the words of the English language and the code ''selezione parole di 5 lettere esistenti.c'' filters all 5-letter words only saving the results into ''parole_vere.txt''. 
The file ''frequenza.c'' calculates the probabilty of each letter to be in all the 5 avalible position. It takes in input ''parole_vere.txt'' and saves in ''statistiche.txt''. 
The file ''surprisal.c'' takes as input ''parole_vere.txt'' and ''statistiche.txt'' and calculate the surprisal (H(X) = -\sum_{i=1}^{n} p_i \log(p_i)) of each word. The results are  in ''surprisal.txt''. 

Please note: The project has no ambition of theoretical formalism of construction of a measurement function starting from a categorical dataset since at the date of its realization I was only in the first year and I had not followed the necessary courses. But I think it can still be interesting. :-)
