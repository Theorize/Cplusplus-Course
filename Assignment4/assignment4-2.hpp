#include <vector>
#include "Vector_old.hpp"
#include <algorithm>

// Computes the distances of all points in the range [begin,end) to a given query point.
//
// The results are stored in the Range starting with distanceBegin having the same length
// as the range of points. The i-th element of the range stores the distance of the i-th point
// in the range to the query point as a double value.
// 
// The supplied iterators can be assumed to be bidirectional
template<class SetIterator, class DistanceIterator>
void computeDistances(
	SetIterator begin, SetIterator end,//pointers to the start and end of the set of points
	Vector const& query, //the query point 
	DistanceIterator distanceBegin //iterator to the beginning of the range storing the distances
){
	SetIterator position = begin;
	Vector difference(begin -> GetSize());
	while(position != end){
		//calculate distance between the two points.
		difference = query - *position;
		//set *distanceBegin = the distance
		*distanceBegin = difference.CalculateNorm(2);

		++distanceBegin;
		++position;
	}
}


// class representing a Pair of a distance and an iterator to the point it refers to.
template<class Iterator>
struct Pair{
	double distance;
	Iterator iterator;
};

//
template<class Iterator>
bool pairCompare(const Pair<Iterator>& firstElem, const Pair<Iterator>& secondElem) {
  return firstElem.distance < secondElem.distance;
}


// Computes the distances of all points in the range [begin,end) to a given query point
// and returns a sorted array of pairs: the distance to the query point and the iterator
// in the range that has this distance.
//
// Elements are returned in ascending order, i.e. the pair with the smallest distance
// is at the front, next is the pair with the second smallest distance, etc.
template<class SetIterator>
std::vector<Pair<SetIterator> > createSortedPointDistancePairs(
	SetIterator begin, SetIterator end,//pointers to the start and end of the set of points
	Vector const& query //the query point 
){
	//Create std::vector to store distances
	std::vector<double> dist(std::distance(begin, end));
	std::vector<double>::iterator distanceBegin = dist.begin();
	//Call ComputeDistances and save results to the vector
	computeDistances(begin, end, query, distanceBegin);
	//Create the pair list
	std::vector<Pair<SetIterator> > results;
	//populate list
	SetIterator position = begin;
	while(position != end){
		struct Pair<SetIterator> next;
		next.distance = *distanceBegin;
		next.iterator = position;
		results.push_back(next);
		distanceBegin++;
		position++;
	}


	std::sort(results.begin(), results.end(), pairCompare<SetIterator>);
	return results;

}


//Returns the Iterators to the k nearest neighbours of a given query point.
//
// The iterators are sorted in ascending order by distance to the query point.
//
// The set of points is given in the range [begin,end].
template<class SetIterator>
std::vector<SetIterator> kNearestNeighbour(
	SetIterator begin, SetIterator end,//pointers to the start and end of the set of points
	Vector const& query, //the query point 
	unsigned int k // the k nearest neighbours that are going to be returned
){
	std::vector<Pair<SetIterator> > Results = createSortedPointDistancePairs(begin, end, query);
	std::vector<SetIterator> NearNeighbour;
	for(int i = 0; i < k; i++){
		NearNeighbour.push_back(Results[i].iterator);
	}
	return NearNeighbour;
}






























