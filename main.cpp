#include <mlpack/core.hpp>
#include <iostream>
#include <mlpack.hpp>
#include <fstream>
#include <string>
#include <chrono>
using namespace arma;
using namespace mlpack;
using namespace std;



int main(){

	mat dataset;
	Row<size_t> labels;
	int number_to_print;
	string path_to_predict;

	cout << "Enter path to file, with You wish to make a prediction:" << endl;
	cin >> path_to_predict;		

     	cout << "Enter number of labels that You wish to display:" << endl;
	cin >> number_to_print;

  	//Load data
	cout << "Begin of loading data" << endl;
	auto start = std::chrono::high_resolution_clock::now();
	if (!data::Load("features_train.csv", dataset))
		throw std::runtime_error("Could not read features_train.csv!");
	cout << "Loaded features_train.csv" << endl;

	if (!data::Load("labels_train_one.csv", labels))
		throw std::runtime_error("Could not read labels_train.csv!");
	cout << "Loaded labels_train.csv" << endl;

	//load provided dataset
        mat dataset_to_predict;     
        if (!data::Load(path_to_predict, dataset_to_predict)) throw std::runtime_error("Could not read provided data!"); 
	cout << "Loaded " << path_to_predict <<endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
	cout << "Data has been loaded, loading time: " << duration.count() << " seconds" << endl;


	//split dataset
	mat trainDataset, testDataset;
	Row<size_t> trainLabels, testLabels;
	data::Split(dataset, labels, trainDataset, testDataset, trainLabels, testLabels, 0.3);	


	//set model
	cout << "Begin of fitting"<< endl;
	start = std::chrono::high_resolution_clock::now();
  	RandomForest<> r(trainDataset, trainLabels, 10, 10, 3);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
	cout << "End of fitting, fitting time: " << duration.count() << " seconds" << endl;

	//make predictions on training dataset
	Row<size_t> trainPredictions;
        r.Classify(trainDataset, trainPredictions);
        const double trainError = arma::accu(trainPredictions != trainLabels) * 100.0 / trainLabels.n_elem;
        cout << "Training error: " << trainError << "%." << endl;

	//make predictions on test dataset
        Row<size_t> testPredictions;
        r.Classify(testDataset, testPredictions);
        const double testError = arma::accu(testPredictions != testLabels) * 100.0 / testLabels.n_elem;
        cout << "Test error: " << testError << "%." << endl;

 	
	//make predictions on provided dataset
        Row<size_t> Predictions;
        r.Classify(dataset_to_predict, testPredictions);

	//save output to file
	std::ofstream outputFile("output.txt");
	for (int i; i < testPredictions.size(); i++){
		outputFile << testPredictions[i] << " ";
	}
	outputFile.close();

        // display example predictions
	cout << "Labels of first " << number_to_print << " features:" << endl;
        for (int i = 0; i < number_to_print; i++){
        switch (testPredictions[i])
	{
		case 0:
		  cout << i + 1 <<". T-shirt/top ";
		  break;
		case 1:
		  cout << i + 1 <<". Trouser ";
		  break;
		case 2:
		  cout << i + 1<<". Pullover ";
		  break;
		case 3:
		  cout << i + 1<<". Dress ";
		  break;
		case 4:
		  cout << i + 1<<". Coat ";
		  break;
		case 5:
		  cout << i + 1<<". Sandal ";
		  break;
		case 6:
		  cout << i + 1<<". Shirt ";
		  break;
		case 7:
		  cout << i + 1<<". Sneaker ";
		  break;
		case 8:
		  cout << i + 1<<". Bag ";
		  break;
		case 9:
		  cout << i + 1<<". Ankle boot ";
		  break;
	}
      cout << "\n";
    }

	



	
	return 0;
}
