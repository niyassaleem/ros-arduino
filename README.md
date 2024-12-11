

**ROS Controlled Robot**

This project demonstrates a **ROS (Robot Operating System)**-based robot that responds to velocity commands by moving in different directions. It integrates ROS topics with an Arduino-based microcontroller to control motor actions like moving forward, backward, and turning left or right. The robot subscribes to velocity commands (`geometry_msgs/Twist`) and executes corresponding motor actions.

---

**Features**
- **ROS Integration**:
  - Subscribes to the `turtle1/cmd_vel` topic for velocity commands.
- **Motor Control**:
  - Controls DC motors to move the robot **forward**, **backward**, and **turn left or right** based on linear and angular velocity inputs.
- **Compact Design**:
  - Efficiently utilizes Arduino and ROS for communication and motor actuation.

---

## **Components**
### **Hardware**
1. **Arduino Board**: Used for motor control and ROS communication.
2. **H-Bridge Motor Driver**: Controls the direction and speed of the motors.
3. **DC Motors**: Provides movement for the robot.
4. **Power Supply**: Powers the motors and microcontroller.

### **Software**
1. **ROS**: For handling communication between the controller and the robot.
2. **Arduino IDE**: For programming the microcontroller.

---

## **How It Works**
1. **Velocity Command Subscription**:
   - The robot subscribes to the `turtle1/cmd_vel` topic and processes the `geometry_msgs/Twist` message.
   
2. **Motor Actions**:
   - **Forward**: Triggered by positive `linear.x`.
   - **Backward**: Triggered by negative `linear.x`.
   - **Turn Left**: Triggered by positive `angular.z`.
   - **Turn Right**: Triggered by negative `angular.z`.
   - **Stop**: When both `linear.x` and `angular.z` are zero.

3. **Motor Pins**:
   - Pins `6`, `7`, `8`, and `9` control the motors based on the received commands.

---

## **Setup Instructions**
1. **Hardware Connections**:
   - Connect motor driver inputs to Arduino pins `6`, `7`, `8`, and `9`.
   - Connect DC motors to the motor driver outputs.

2. **Install ROS**:
   - Ensure ROS is installed on your system.
   - Configure a ROS workspace with the necessary `geometry_msgs/Twist` package.

3. **Upload Code**:
   - Open the Arduino IDE and upload the provided code to your Arduino board.

4. **ROS Node Setup**:
   - Launch the ROS core.
   - Run the ROS node that publishes `geometry_msgs/Twist` messages to the `turtle1/cmd_vel` topic.

---

## **Usage**
1. **Start the ROS Core**:
   ```bash
   roscore
   ```
2. **Publish Velocity Commands**:
   - Use the following command to send velocity commands to the robot:
     ```bash
     rostopic pub /turtle1/cmd_vel geometry_msgs/Twist "linear:
       x: 1.0
       y: 0.0
       z: 0.0
     angular:
       x: 0.0
       y: 0.0
       z: 0.5"
     ```
   - Replace values of `linear.x` and `angular.z` to control movement.

3. **Observe the Robot's Behavior**:
   - The robot will move forward, backward, or turn based on the published commands.

---

## **Code Structure**
```plaintext
ROS_Controlled_Robot/
├── ROS_Arduino_Code.ino      # Arduino code for motor control and ROS integration
└── README.md                 # Project documentation
```

---

## **Future Improvements**
- Add **sensor feedback** (e.g., ultrasonic sensors) for obstacle avoidance.
- Include **odometry** to track the robot's movement.
- Enhance with **remote control** using a ROS GUI or mobile app.

---

## **License**
This project is licensed under the **MIT License**. See the `LICENSE` file for details.

---

## **Acknowledgements**
Special thanks to the ROS and Arduino communities for providing excellent resources and documentation.

---

Let me know if you'd like to add or modify any section!
