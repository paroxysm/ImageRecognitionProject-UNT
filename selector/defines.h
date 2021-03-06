#ifndef DEFINES_H
#define DEFINES_H

/*
 * Keep track of when mouse is dragging on the named window.
 * dragging will be true after left button is pressed,
 * and false when the left button is released.  
 */
bool dragging = false;

/*
 * Set to true when dragging stops
 */
bool finished = false;

/*
 * Set to false when the GUI needs to be closed
 */
bool running = true;

/*
 * When true, show the help menu.
 */
bool help = false;

/*
 * If use_edges is true, display the edge map
 * instead of the original image.
 */
bool useEdges = false;

/*
 * If reduce_noise is true, apply a median blur
 * (simple noise reduction).
 */
bool reduceNoise = false;

/*
 * If max_contrast is true, convert the image
 * to its maximum contrast.
 */
bool maxContrast = false;

/*
 * Contains coordinates for the selected image - not used
 */
Rect selection;

/* Object that was selected by the user along with it's key points and descriptors calculated upon acquisition */
Mat selectedImage;
Mat selectedImageDescriptors;
vector<KeyPoint> selectedImageKeypoints;

/* Current frame being processed */
Mat currentFrame;

/* We cache these just in case we come up w/ a way to determine when not to recalculate keypoints and descriptors. Maybe skipping frames, iunno */
Mat currentFrameDescriptors;
vector<KeyPoint> currentFrameKeypoints;

//Keeps tracks of each frame, might come in handy for sequencing frames dispatched to threads for processing.
unsigned long long frameCounter = 0;

/*
 * Called when the named window gets a mouse event.
 */
void mouseCallback(int event, int x, int y, int flags, void* param);

/*
 * Break the image into its channels and equalize their histograms.
 */
void maximizeContrast(Mat &input, Mat &output);

/*
 * Given an input image, we detect 'selectedObject' in that image and draw a border around it.
 */
bool findSelection(Mat&);

/*
 * Ridiculous hack to put text on newlines...
 * Each array index is effectively a new line.
 */
const char *helpArray[] = {"q   -- quit.",
							"h   -- toggle this menu",
							"e   -- toggle edge map",
							"r   -- reduce noise (median blur)",
							"c   -- maximize contrast"};
/*
 * Length of help_array
 */
#define HELP_LENGTH 5
#define MIN_SIZE 10

/*
 * Define these once
 */
SurfDescriptorExtractor extractor;
SurfFeatureDetector surf(100);


/* How many frames we skip - not used */
unsigned const SKIP_EVERY_XFRAMES = 3;

#endif
