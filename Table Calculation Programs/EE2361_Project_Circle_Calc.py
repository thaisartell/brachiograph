import math

def generate_circle_commands(center_x, center_y, radius, num_points):
    # List to store the C code commands
    c_commands = []
    
    # Calculate the angle between each point
    angle_step = 2 * math.pi / num_points
    
    # Start generating the C commands
    for i in range(num_points):
        # Calculate the angle for this point
        angle = i * angle_step
        
        # Calculate the x and y coordinates of the point
        x = int(center_x + radius * math.cos(angle))
        y = int(center_y + radius * math.sin(angle))
        
        # Generate C command to move to (x, y)
        c_commands.append(f"move_to({x}, {y}, CYCLES_TO_TRAVEL);")
    
    return c_commands

# Example usage
center_x = 512*64  # Center of the circle (X)
center_y = 512*64  # Center of the circle (Y)
radius = 256*64     # Radius of the circle
num_points = 16  # Number of points to approximate the circle

commands = generate_circle_commands(center_x, center_y, radius, num_points)

# Print the generated C commands
for command in commands:
    print(command)