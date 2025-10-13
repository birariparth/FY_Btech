import time
import sys

def type_lyric(line, char_delay=0.13):
    for char in line:
        print(char, end='', flush=True)
        time.sleep(char_delay)
    print()  # New line after the line is fully printed

def print_lyrics():
    lyrics = [
        "I saw her in the rightest way",
        "Looking like Anne Hathaway",
        "Laughing while she hit her pen,",
        "and coughed..., and coughed...",
        "And then she came up to my knees",
        "Begging, 'Baby would you please",
        "Do the things you said you'd do to me...., to me...?'",
        "Oh won't you kiss me on the mouth and love me like a sailor?",
        "And when you get a taste, can you tell me what's my flavour?",
        "I don't believe in God, but I believe that you're my saviour",
        "My mom says that she's worried, but I'm covered in His favor",
    ]

    #Delay between lines
    delays = [1.3, 1.4, 1.0, 1.6, 1.1, 0.8, 0.7, 0.7, 0.7, 0.5, 0.5]

    #Character typing speed per line (in seconds)
    char_delays = [
        0.13,  #slow
        0.13,
        0.13,
        0.13,
        0.13,
        0.12,  #slightly faster
        0.16,
        0.08,  #getting quicker
        0.08,
        0.08,
        0.08   #fastest
    ]

    print("\n")
    time.sleep(1.5)

    for i, line in enumerate(lyrics):
        type_lyric(line, char_delay=char_delays[i])
        time.sleep(delays[i])

print_lyrics()