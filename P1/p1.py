import soundfile as sf
import matplotlib.pyplot as plt
import numpy as np

signal, fm = sf.read("task-edited.au")
t = np.arange(0, len(signal)) / fm  
plt.plot(t, signal)
plt.show()