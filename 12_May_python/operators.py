# for arithmatic operator 
# print(7/3)
# print(7//3) #floor value
# #MEMBERSHIP OPERATOR
# mylist = [1,2,3,4,5]
# print(9 in mylist)
# print(9 not in mylist)
# # identity operator
# x = [1,2,3]
# y = [1,2,3]
# z=x
# print(x is z) #true impleies both are pointing to the same object
# print(x is y) 
# print(x==y) #it just compares the value
# # exploration
# # import webbrowser
# # webbrowser.open("https://docs.python.org/3/tutorial/")
# # text to speech conversion using pyttsx3
import pyttsx3
engine = pyttsx3.init()
engine.say("why are you sad")
engine.runAndWait()
print("Engine is running")
