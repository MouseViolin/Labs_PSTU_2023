import os
import requests
import sys

# Получение пути к файлу с сообщением из аргументов командной строки
file_path = sys.argv[1]

# Чтение сообщения из файла
with open(file_path, 'r') as file:
    message = file.read()
    print("Принято сообщение из файла:", message)

#  Токен  бота и chat_id, куда нужно отправить файл
TOKEN = 'О.о'
CHAT_ID = 'О.о'

# Укажите путь к папке, где находятся файлы
FOLDER_PATH = '/Users/user/Documents/Qt/arm/reports'

# Получаем список всех файлов в папке
files = os.listdir(FOLDER_PATH)

# Сортируем список файлов по времени последнего изменения
files.sort(key=lambda x: os.path.getmtime(os.path.join(FOLDER_PATH, x)))

# Берем последний файл из отсортированного списка
latest_file = files[-1]

# Формируем путь к последнему файлу
file_path = os.path.join(FOLDER_PATH, latest_file)

# URL для отправки файла через Telegram Bot API
url = f'https://api.telegram.org/bot{TOKEN}/sendDocument'

# Открываем файл в двоичном режиме для чтения
with open(file_path, 'rb') as file:
    files = {'document': file}

    # Дополнительные параметры запроса: chat_id и caption
    params = {
        'chat_id': CHAT_ID,
        'caption': message
    }

    # Отправляем POST-запрос с файлом
    response = requests.post(url, params=params, files=files)


