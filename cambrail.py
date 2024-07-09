import cv2
import pytesseract
import serial

cam = cv2.VideoCapture(1)
arduinoData = serial.Serial('COM4',9600)
cv2.namedWindow("test")

while True:
    ret, frame = cam.read()
    cv2.imshow("test",frame)
    if not ret:
        break
    k = cv2.waitKey(1)

    if k%256 == 27:
        # ESC pressed
        print("Escape hit, closing...")
        break

    elif k%256 == 32:
        # SPACE pressed
        text = pytesseract.image_to_string(frame, lang = 'eng')
        print(text)
        print(text[0])
        print(text[1])
        arduinoData.write('{}'.format(text[0]).encode())
        arduinoData.write('{}'.format(text[1]).encode())

cam.release()

cv2.destroyAllWindows()
