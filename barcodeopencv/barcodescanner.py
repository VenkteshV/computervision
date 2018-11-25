from __future__ import print_function
import pyzbar.pyzbar as pyzbar
import numpy as numpy

import cv2

def decode(image) :
    decodedObjects = pyzbar.decode(image)

    for obj in decodedObjects :
        print('Type :', obj.type)
        print('Data :', obj.data, '\n')
    return decodedObjects

def display(image, decodedObjects) :
    for decodedObject in decodedObjects :
        points = decodedObject.polygon

        if len(points) > 4 :
            hull = cv2.convexHull(np.array([point for point in points], dtype = np.float32))
            hull = list(map(tuple, np.squeeze(hull)))
        else :
            hull = points
        n = len(hull)
        for j in range(0,n):
            cv2.line(im, hull[j], hull[ (j+1) % n], (255,0,0), 3)    
        cv2.imshow( "results",im)
        cv2.waitKey(0)

if __name__ == '__main__':
    im = cv2.imread('zbar-test.jpg')
    print('eher')
    decodedImage = decode(im)
    display(im, decodedImage)