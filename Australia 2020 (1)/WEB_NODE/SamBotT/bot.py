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
	markup = types.InlineKeyboardMarkup(row_width=2)
	item1  = types.InlineKeyboardButton("random number" ,callback_data= 'random')
	item2 = types.InlineKeyboardButton("Hey !",callback_data ='good')
    item3 = types.InlineKeyboardButton("Weather", callback_data='bad')

    markup.add(item1,item2,item3)

	bot.send_message(message.chat.id, "Welcome , {0.first_name}!\n I am - <b>{1.first_name}</b>, bot which was created by Shishov Mikhail."format(message.from_user, bot.get_me()),
		parse_mode='html')


def response_speech(message):
	if message.chat.type == 'private':
		if message.text == "random number":
			bot.send_message(message.chat.id, str(random.randit(0,1004300)))
		elif message.text = "Hey !":
			bot.send_message(message.chat.id, "Hi, sweet one!" , reply_markup=markup)
		else:
			bot.send_message(message.chat.id, "I cant show weather")
         
@bot.callback_query_handler(func=lambda call:True)
def callback_inline(call):
	try:
		if call.message:
			if call.data == 'good':

				bot.send_message(call.message.chat.id , 'Nice')
			elif call.data == ' bad':
				bot.send_message(call.message.chat.id , 'Things happen')


				#remove inline buttons
				bot.edit_message_text(chat_id=call.message.chat.id, message_id=call.message.message_id, text="random",
                reply_markup=None)

				


bot.polling(none_stop = True)


