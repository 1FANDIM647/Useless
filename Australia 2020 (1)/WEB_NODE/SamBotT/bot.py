import telebot
import config 
import random

from telebot import types


bot = telebot.TeleBot(config.TOKEN)


@bot.message_handler(content_types=['text'])

def welcome_speech(message):
	#sti=open('static/welcome_speech.webp','rb') send sticker
	#bot.send_sticker(message.chat.id, sti)
    
    #keyboard
	markup = types.ReplyKeyboardMarkup(resize_keyboard = True)
	item1  = types.KeyboardButton("random number")
	item2 = types.KeyboardButton("Hey !")
    item3 = types.KeyboardButton("Weather")

    markup.add(item1,item2,item3)

	bot.send_message(message.chat.id, "Welcome , {0.first_name}!\n I am - <b>{1.first_name}</b>, bot which was created by Shishov Mikhail."format(message.from_user, bot.get_me()),
		parse_mode='html')


def response_speech(message):
	bot.send_message(message.chat.id, message.text)#bot will write , that you wrote

bot.polling(none_stop = True)


