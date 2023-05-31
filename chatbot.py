import nltk
from nltk.chat.util import Chat, reflections

pairs = [
[
r"my name is (.*)",
["Hello %1, I am GPT Lite. How are you ?",]
],

[
r"hi|hello|hey",
["Hello, I am GPT Lite. How are you ?", "Hey there, I am GPT Lite. How are you ?",]
],

[ 
r"what is your name ?",
["I am GPT Lite created during mock exams. You can tell me anything ! I am good at keeping secret.",]
],

[
r"how are you ?",
["I am fine as always. How about you ?", ]
],

[
r"I am fine", 
["Great to hear that", "You can share your thoughts with me, I am a good listner",]
]
]

print("Begin")
def chat():
	print("Hi, chatbot at your service")
	chat = Chat(pairs, reflections)
	chat.converse()
	return 0

chat()
