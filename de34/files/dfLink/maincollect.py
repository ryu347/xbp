import dfLink
import time
import serial

# 端末設定
# 端末keyを指定してください。
pkey = 'r0AJN9SkaFEf0nrLfS5v'

# シリアルポートを入力
# serial_serch.pyでシリアルポートを検索してください
serial_port = '/dev/tty.usbserial-130'  # 正しいシリアルポートに置き換えてください

# Arduinoとのシリアル通信設定
my_arduino = serial.Serial(serial_port, 9600)

# ステッピングモーター制御用の変数
steps_per_revolution = 1900

while True:
    # IoTサーバーからデータの取得
    data_list = dfLink.getData_From_dfLink(pkey=pkey)
    # リスト形式で取得される
    print(data_list)

    # 最初データ（0番目)の塊の中の2番目のデータを読みたい（0から始まるので、本当は3番目)
    try:
        int_data = int(data_list[0][2])
        print(int_data)

        # ステッピングモーターの制御
        if int_data == 1:
            # 3秒回転
            my_arduino.write(b'1')  # 文字列 '1' をバイト列に変換
            time.sleep(3)
            # 停止
            my_arduino.write(b'0')  # 文字列 '0' をバイト列に変換
            my_arduino.write(b'D')  # データ受信停止のコマンドを送信
            time.sleep(5)
            # 3秒逆回転
            my_arduino.write(b'-1')  # 文字列 '-1' をバイト列に変換
            time.sleep(3)
            # 停止
            my_arduino.write(b'0')  # 文字列 '0' をバイト列に変換
            my_arduino.write(b'D')  # データ受信停止のコマンドを送信
        else:
            # 停止
            my_arduino.write(b'0')  # 文字列 '0' をバイト列に変換
            my_arduino.write(b'D')  # データ受信停止のコマンドを送信

    except:
        print("データなし")