# Word-Prediction

There are a number of reasons why we would want to keep track of the set of potential words that follow a particular word in text documents. One reason is for word prediction. While we can predict the word you’re currently typing based purely on the letters you’ve typed so far, successful prediction goes up when you keep track of the set of words that are likely to follow a particular word and limit your predictions to that set of word. Another reason is for speech recognition – again, if we know what word an individual has just said, we have a better chance of successfully predicting the current word if we can limit (or at least favor) words we know are likely to follow the previous word.


We’ll be using this word and set of following words to generate text in a particular “voice”. By voice, I mean the patterns with which different authors use words. Every author has their own unique word patterns. For this example, we’ll be emulating Dr. Seuss’ voice, although you could easily attempt to emulate Poe, Dickens, or Shakespeare.

In my example, we will be reading in a text file of Dr. Seuss stories. Each word read in will be a key, and the values associated with each key will be an array of Strings, or the set of words that follow a word. So, for instance, if you have the word “I” as your key, the array of values might be a list that would look like {“do”,”see”,”have”,”am”,”do”,”need”}, etc. The value that is associated with the key “I” is every word in the Dr. Seuss text that follows the word “I”.
