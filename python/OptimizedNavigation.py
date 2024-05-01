import csv
import math

class Navigator:

    destinations = []
    used_destinations = []
    total_travel_time = 0

    class Destination:
        x = 0
        y = 0
        def __init__ (self, x_coord, y_coord):
            self.x = x_coord
            self.y = y_coord

    def __init__(self, destinations_csv):
        with open(destinations_csv, newline='') as file:
            self.destinations = list(csv.reader(file, delimiter=',', quotechar='|'))
            self.destinations = self.destinations[1:]
            self.destinations = [self.Destination(int(item[0]), int(item[1])) 
                                           for item in self.destinations]

    def travel_time(self, distance, passenger_count):
        travel_time = distance * (1 + passenger_count / 100)
        return travel_time
    
    def printer(self):
        count = 0
        for destination in self.used_destinations:
            print(f"Station {count}: " + str(destination.x) + ", " + str(destination.y))
            count += 1
        print("---")
        print("Total Travel Time: " + str(self.total_travel_time))
    
    """
    We need to make sure that the crew is not sailing directly
    North, and also not going South to ensure we compute the
    shortest distance to the final destination.
    """
    def direction_validator(self, direction):
        if ((direction[0] != 0)):
            return True
        else:
            return False

    def journey(self):
        if (self.destinations):
            passenger_count = 10
            self.used_destinations.append(self.destinations[0])
            current_position = self.Destination(self.destinations[0].x, self.destinations[0].y)
            while (len(self.used_destinations) < len(self.destinations)):
                least_distance_target = None
                least_time = 0
                for potential_target in self.destinations:
                    if (potential_target not in self.used_destinations):
                        direction = [potential_target.x - current_position.x, 
                                    potential_target.y - current_position.y]
                        if self.direction_validator(direction):
                            distance = math.sqrt((potential_target.x - current_position.x) * 
                                                (potential_target.x - current_position.x) +
                                                (potential_target.y - current_position.y) * 
                                                (potential_target.y - current_position.y))
                            travel_time = self.travel_time(distance, passenger_count)
                            if (least_time == 0):
                                least_time = travel_time
                            if (travel_time <= least_time):
                                least_time = travel_time
                                least_distance_target = potential_target
                if (least_distance_target):
                    self.used_destinations.append(least_distance_target)
                    current_position = least_distance_target
                    self.total_travel_time += least_time
                    # Add 10 more passengers on every stop
                    passenger_count += 10

if __name__ == "__main__":
    nav = Navigator('1_novel_navigation.csv')
    nav.journey()
    nav.printer()