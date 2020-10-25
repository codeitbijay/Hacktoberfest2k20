import unittest
import MetaDataImage as mdi

class MetaDataImageTest(unittest.TestCase):

    def test_is_directory(self):
        self.assertTrue(mdi.is_directory('./'))
        #self.assertFalse(mdi.is_directory('/Users/Downloads/test_image.jpg'))
    
    def test_file_format(self):
        for file_format in ["test.jpg","test.JPG","test.jpeg","test.JPEG"]:
            self.assertTrue(mdi.check_file_format(file_format))
        for file_format in ["test.mp4","test.xlsx","test.MP4","test.html"]:
            self.assertFalse(mdi.check_file_format(file_format))


if __name__ == '__main__':
    unittest.main()