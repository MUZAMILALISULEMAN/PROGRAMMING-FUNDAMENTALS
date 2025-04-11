#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char title[100];
	double rating;
	int runtime;
	char encodingFormat[50];
} ContentMetadata;
double** createEngagementMatrix(int numUsers, int numCategories) {
	double** engagementMatrix = (double**)malloc(numUsers * sizeof(double*));
	for (int i = 0; i < numUsers; i++) {
		engagementMatrix[i] = (double*)malloc(numCategories * sizeof(double));
		for (int j = 0; j < numCategories; j++) {
			engagementMatrix[i][j] = 0.0;
		}
	}
	return engagementMatrix;
}
int** createDevicePreferencesMatrix(int numUsers, int numDevices) {
	int** devicePreferences = (int**)malloc(numUsers * sizeof(int*));
	for (int i = 0; i < numUsers; i++) {
		devicePreferences[i] = (int*)malloc(numDevices * sizeof(int));
		for (int j = 0; j < numDevices; j++) {
			devicePreferences[i][j] = 720;
		}
	}
	return devicePreferences;
}
ContentMetadata** createContentMatrix(int numCategories, int numContents) {
	ContentMetadata** contentMatrix = (ContentMetadata**)malloc(numCategories * sizeof(ContentMetadata*));
	for (int i = 0; i < numCategories; i++) {
		contentMatrix[i] = (ContentMetadata*)malloc(numContents * sizeof(ContentMetadata));

		for (int j = 0; j < numContents; j++) {
			snprintf(contentMatrix[i][j].title, sizeof(contentMatrix[i][j].title), "Content %d-%d", i, j);
			contentMatrix[i][j].rating = (rand() % 100) / 10.0; // Random rating between 0.0 and 10.0
			contentMatrix[i][j].runtime = (rand() % 120) + 60; // Random runtime between 60 and 180 minutes
			snprintf(contentMatrix[i][j].encodingFormat, sizeof(contentMatrix[i][j].encodingFormat), "Format %d", j);
		}
	}
	return contentMatrix;
}


void displayEngagementMatrix(double** engagementMatrix, int numUsers, int numCategories) {
	printf("Engagement Matrix:\n");
	for (int i = 0; i < numUsers; i++) {
		for (int j = 0; j < numCategories; j++) {
			printf("%.2f ", engagementMatrix[i][j]);
		}
		printf("\n");
	}
}
void displayDevicePreferences(int** devicePreferences, int numUsers, int numDevices) {
	printf("Device Preferences Matrix:\n");
	for (int i = 0; i < numUsers; i++) {
		for (int j = 0; j < numDevices; j++) {
			printf("%d ", devicePreferences[i][j]);
		}
		printf("\n");
	}
}
void displayContentMatrix(ContentMetadata** contentMatrix, int numCategories, int numContents) {
	printf("Content Metadata Matrix:\n");
	for (int i = 0; i < numCategories; i++) {
		for (int j = 0; j < numContents; j++) {
			printf("Title: %s, Rating: %.1f, Runtime: %d min, Encoding: %s\n",
			       contentMatrix[i][j].title, contentMatrix[i][j].rating, contentMatrix[i][j].runtime, contentMatrix[i][j].encodingFormat);
		}
	}
}

// Main function
int main() {
	int numUsers = 3;
	int numCategories = 2;
	int numDevices = 2;
	int numContents = 3;
	double** engagementMatrix = createEngagementMatrix(numUsers, numCategories);
	int** devicePreferences = createDevicePreferencesMatrix(numUsers, numDevices);
	ContentMetadata** contentMatrix = createContentMatrix(numCategories, numContents);
	engagementMatrix[0][0] = 120.5;
	engagementMatrix[1][1] = 95.0;
	devicePreferences[0][0] = 1080;
	devicePreferences[1][1] = 1440;
	displayEngagementMatrix(engagementMatrix, numUsers, numCategories);
	displayDevicePreferences(devicePreferences, numUsers, numDevices);
	displayContentMatrix(contentMatrix, numCategories, numContents);
	for (int i = 0; i < numUsers; i++) {
		free(engagementMatrix[i]);
		free(devicePreferences[i]);
	}
	free(engagementMatrix);
	free(devicePreferences);

	for (int i = 0; i < numCategories; i++) {
		free(contentMatrix[i]);
	}
	free(contentMatrix);

	return 0;
}