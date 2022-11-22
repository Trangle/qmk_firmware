from PIL import Image, ImageSequence, GifImagePlugin
from PIL import GifImagePlugin
import numpy as np

# Open source
imageObject = Image.open("../gifs/ikun_switch.gif")
# Get sequence iterator
frames = ImageSequence.Iterator(imageObject)
# Output (max) size
size = 80, 160

print(imageObject.is_animated)

print(imageObject.n_frames)

print(imageObject.size)

# Wrap on-the-fly thumbnail generator
def thumbnails(frames):
    i = 0
    for frame in frames:
        i += 1
        if (i >= 4):
            break
        thumbnail = frame.resize((160,80)).rotate(270, expand=True).copy()
        thumbnail.thumbnail(size, Image.Resampling.LANCZOS)
        yield thumbnail

frames = thumbnails(frames)

# Save output
om = next(frames) # Handle first frame separately
om.info = imageObject.info # Copy sequence info
om.save("../gifs/ikun_switch_st7735s.gif", save_all=True, append_images=list(frames))

