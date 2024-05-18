import os

# Specify the directory
directory = '.'

# Iterate over all files in the directory
for filename in os.listdir(directory):
    if filename.endswith('.exe'):
        file_path = os.path.join(directory, filename)
        os.remove(file_path)
        print(f"Deleted {file_path}")

print("All .exe files have been deleted.")
