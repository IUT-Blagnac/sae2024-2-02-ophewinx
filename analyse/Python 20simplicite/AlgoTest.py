import unittest
from simplicite20 import simplicite 

class TestSimplicite(unittest.TestCase):

    def test_RLE(self):
        self.assertEqual("", simplicite.RLE(""))
        self.assertEqual("1a1b1c", simplicite.RLE("abc"))
        self.assertEqual("1a2b3c", simplicite.RLE("abbccc"))
        self.assertEqual("3a1b2a", simplicite.RLE("aaabaa"))
        self.assertEqual("1a1A1a", simplicite.RLE("aAa"))
        self.assertEqual("9W4W", simplicite.RLE("WWWWWWWWWWWWW"))

    def test_RLERecursif(self):
        self.assertEqual("", simplicite.RLER("", 1))
        self.assertEqual("", simplicite.RLER("", 3))
        self.assertEqual("1a1b1c", simplicite.RLER("abc", 1))
        self.assertEqual("1a2b3c", simplicite.RLER("abbccc", 1))
        self.assertEqual("3a1b2a", simplicite.RLER("aaabaa", 1))
        self.assertEqual("1a1A1a", simplicite.RLER("aAa", 1))
        self.assertEqual("111a111b111c", simplicite.RLER("abc", 2))
        self.assertEqual("311a311b311c", simplicite.RLER("abc", 3))

    def test_unRLE(self):
        self.assertEqual("", simplicite.unRLE(""))
        self.assertEqual("abc", simplicite.unRLE("1a1b1c"))
        self.assertEqual("abbccc", simplicite.unRLE("1a2b3c"))
        self.assertEqual("aaabaa", simplicite.unRLE("3a1b2a"))
        self.assertEqual("aAa", simplicite.unRLE("1a1A1a"))
        self.assertEqual("WWWWWWWWWWWWW", simplicite.unRLE("9W4W"))

    def test_unRLERecursif(self):
        self.assertEqual("", simplicite.unRLER("", 1))
        self.assertEqual("", simplicite.unRLER("", 3))
        self.assertEqual("abc", simplicite.unRLER("1a1b1c", 1))
        self.assertEqual("abbccc", simplicite.unRLER("1a2b3c", 1))
        self.assertEqual("aaabaa", simplicite.unRLER("3a1b2a", 1))
        self.assertEqual("aAa", simplicite.unRLER("1a1A1a", 1))
        self.assertEqual("abc", simplicite.unRLER("111a111b111c", 2))
        self.assertEqual("abc", simplicite.unRLER("311a311b311c", 3))

    def test_Performance(self):
        self.assertEqual("wwwbzzzzzzzzzz", simplicite.unRLER(simplicite.RLER("wwwbzzzzzzzzzz", 30), 30))

if __name__ == '__main__':
    unittest.main()