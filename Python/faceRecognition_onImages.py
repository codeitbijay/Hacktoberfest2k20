import face_recognition
import os
import cv2

known_faces_dir='images/known'
unknown_faces_dir='images/unknown'
frame_tickness=3
font_thickness=2


known_faces=[]
known_names=[]

for name in os.listdir(known_faces_dir):
    for filename in os.listdir(f"{known_faces_dir}/{name}"):
        known_image=face_recognition.load_image_file(f"{known_faces_dir}/{name}/{filename}")
        known_encoding=face_recognition.face_encodings(known_image)[0]
        known_faces.append(known_encoding)
        known_names.append(name)

for filename  in os.listdir(unknown_faces_dir):
    unknown_image=face_recognition.load_image_file(f"{unknown_faces_dir}/{filename}")
    unknown_locations=face_recognition.face_locations(unknown_image)
    unknown_encodings=face_recognition.face_encodings(unknown_image,unknown_locations)

    for unknown_face_encoding,unknown_face_location in zip(unknown_encodings,unknown_locations):
        results=face_recognition.compare_faces(known_faces,unknown_face_encoding)
        match=None
        if True in results:
            match=known_names[results.index(True)]
            print(f'match found : {match}')

            top_left=(unknown_face_location[3],unknown_face_location[0])
            bottom_right=(unknown_face_location[1],unknown_face_location[2])
            color=[0,255,0]
            cv2.rectangle(unknown_image,top_left,bottom_right,color,frame_tickness)

            top_left=(unknown_face_location[3],unknown_face_location[2])
            bottom_right=(unknown_face_location[1],unknown_face_location[2]+22)
            cv2.rectangle(unknown_image,top_left,bottom_right,color,cv2.FILLED)
            cv2.putText(unknown_image,match,(unknown_face_location[3]+10,unknown_face_location[2]+15),cv2.FONT_HERSHEY_SIMPLEX,0.5,(255,0,0),font_thickness)

            
        else:
            print('unknown')

    cv2.imshow(filename,unknown_image)
    cv2.waitKey(0)
    cv2.destroyWindow(filename)
            

            
            
            
