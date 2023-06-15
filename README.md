# Cpp-random-forest-classifier

This repository contains a small machine learning project, which is a random forest classifier trained on the [Fashion MNIST dataset](https://www.kaggle.com/datasets/zalando-research/fashionmnist).
With this program, you will be able to classify your images of clothes into the following 10 categories:

0. T-shirt/top
1. Trouser
2. Pullover
3. Dress
4. Coat
5. Sandal
6. Shirt
7. Sneaker
8. Bag
9. Ankle boot

# Dependencies
This project has been developed and tested with:
- C++14
- mlpack 4.1.0
  
# Input Data
The program requires an input CSV file where each row represents a flattened 28x28 pixel image.
The program will also ask you how many example labels you wish to display on the standard output.

# Output Data
The main output is a TXT file with space-separated labels (in integer format). As mentioned earlier, you will also receive a snippet of several first labels of this data on the standard output in text form.
You will also receive basic information about the training process (e.g. fitting time).

# Train dataset requirements
Because GitHub doesn't allow sending large files, please attach the `features_train.csv` and `labels_train.csv` files to the root directory of this repository before launching the project. The `features_train.csv` file should have the same format as the input CSV file. You can find the Fashion MNIST dataset [here](https://www.kaggle.com/datasets/zalando-research/fashionmnist).
