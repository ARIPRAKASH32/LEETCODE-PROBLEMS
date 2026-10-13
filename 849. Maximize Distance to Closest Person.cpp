class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

        int distanceForFirstSeat = 0;
        int distanceForLastSeat = 0;
        int currentDistance = 0;
        int maxDistance = 0;
        
        if(seats[0] == 0) {
            for(int i = 0; i < seats.size(); i++){
                if(seats[i] == 1) {
                    break;
                }

                distanceForFirstSeat++;
            }
        } else {
            distanceForFirstSeat = -1;
        }

        if(seats[seats.size() - 1] == 0) {
            for(int i = seats.size() - 1; i >= 0; i--){
                if(seats[i] == 1){
                    break;
                }

                distanceForLastSeat++;
            }
        } else {
            distanceForLastSeat = -1;
        }

        for(int i = 1; i < seats.size(); i++){
            if(seats[i] == 0) {

                currentDistance = 0;

                for(int j = i; j < seats.size(); j++) {
                    if(seats[j] == 0) {
                        currentDistance++;
                    }
                    else {
                        currentDistance++;
                        break;
                    }
                }

                if(maxDistance < currentDistance) {
                    maxDistance = currentDistance;
                }
            }
        }

        maxDistance = maxDistance / 2;

        if(maxDistance < distanceForFirstSeat) {
            maxDistance = distanceForFirstSeat;
        }

        if(maxDistance < distanceForLastSeat) {
            maxDistance = distanceForLastSeat;
        }

        return maxDistance;
    }
};
