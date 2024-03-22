# Project duration simulation program

## **Description**

This program deals with simulation aimed at determining the required time for the completion of a project and establishing the variation in the time needed for such a project, all in relation to the size of the project itself and the team working on it, team experience, and the potential for changes within the project. </br>

The simulation uses the PERT (Program Evaluation and Review Technique) model to calculate the required time for project completion. Additionally, alongside the PERT model, other relevant data is utilized to make the simulation as realistic as possible. </br>

Within this simulation, a Monte Carlo simulation is also employed, aiming to determine variations based on a set of data and to establish the general time required for completing a project falling into the previously mentioned category </br>

Randomly generated data within intervals defined by the user is utilized throughout the simulation. </br>

## **Development**
- Languages: C++ </br>

## **Installation**

In the \"Releases\" section, you can find the program (.exe file) available for download and use. </br>

## **Usage**

When using the program, you need to input several pieces of data: </br>

- Interval in which the number of tasks is generated (lower and upper bounds) </br>
- Interval for the duration of tasks in hours (lower and upper bounds) </br>
- Upper bound of the interval in which the percentage probability of changes in tasks is generated (0-100%) </br>
- Option selection for whether the probability of task changes is simulated or included in the final task duration </br>
- Interval in which the number of team members is generated (upper and lower bounds)
- Interval for the experience of team members (0-20): </br>
    \- Experience value less than 10 represents experienced team members </br>
    \- Experience value greater than 10 represents inexperienced team members </br>
- Selection of Monte Carlo simulation options: </br>
    \- Monte Carlo simulation with fixed data (Data generated at the start and used in the PERT model simulation) </br>
    \- Monte Carlo simulation with random data (Data generated randomly in each iteration within predefined intervals set by the user) </br>
- Number of iterations for the Monte Carlo simulation - Selection of option to save generated data in CSV file </br>

## **Features**

- Definition of all possible intervals in which data can be randomly generated. </br>
- Option to select multiple options for certain simulations or data generation. </br>
- Ability to save generated data in CSV files for further analysis. </br>

## **Contribution**

If you have any ideas on how to further expand this simulation, make it even more realistic, or if you find any errors/inconsistencies in the code and the simulation model itself, feel free to create a pull request with your changes, and you will be added to the list of contributors. </br>

## **License**
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## **Contact**

You can contact me via email: kenan.kajtazovic.01@gmail.com. </br>
Also, you can reach me on any platform listed in the description of my GitHub profile.</br>

## **Status**
- **Version**: 1.0.0.</br>
