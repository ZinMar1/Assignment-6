// Created by Zin Mar on 9/30/2022.
//LeaveMangemnt

#include<iostream>
using namespace std;
class Staff{
public:
    int locate=0;
    int currentId=0;
    int currentStaffLeave=0;
    string staffName[100];
    string sPassword[100];
    int staffSalary[100];
    int cLeave[100];
    int mLeave[100];
    int netSalary[100];

    Staff(){
        cout<<"Welcome to our Leave Management System"<<endl;
    }

    int sRegister();
    int login();
    int mainMenu();
    int staffInfo();
    int applyLeave();
    int casualLeave(int currentId, int cleave);
    int medicalLeave(int currentId, int mleave);
};

int Staff::sRegister(){
    string name;
    string password;
    string confirmpass;
    int salary;
    int leave=0;


    cout<<"This is from Registration"<<endl;
    cout<<"Enter your name to register:";
    cin>>name;
    cout<<"Enter your password to register:";
    cin>>password;
    cout<<"Enter your confirm password:";
    cin>>confirmpass;
    cout<<"Enter your Salary:";
    cin>>salary;

    if(password==confirmpass){
        staffName[locate]=name;
        sPassword[locate]=password;
        staffSalary[locate]=salary;
        cLeave[locate]=leave;
        mLeave[locate]=leave;
        netSalary[locate]=salary;
        cout<<"Successful Registration!"<<endl;
        locate++;
        staffInfo();

    }

}

int Staff::login(){
    string lstaffName;
    string lsPassword;
    cout<<"\nThis is from Login."<<endl;
    cout<<"Enter Staff Name to login:";
    cin>>lstaffName;
    cout<<"Enter Password to Login:";
    cin>>lsPassword;

    for(int i=0;i<=locate;i++){
        if(lstaffName==staffName[i] && lsPassword==sPassword[i]){
            currentId=i;
            currentStaffLeave=cLeave[i];
            cout<<"Login Success"<<endl<<endl;
            //staffInfo();
            applyLeave();

        }

        return 100;

    }

}

int Staff::applyLeave() {
    int typeofLeave=0;
    int applyLeaveNum;
    int staffLeave=0;

    cout<<"\nPress 1 to Apply Casual Leave:"<<endl;
    cout<<"Press 2 to Apply Medical Leave:"<<endl;
    cout<<"Press 3 to Quit"<<endl;
    cin>>typeofLeave;

    if(typeofLeave==1){
        cout<<"Type number of casual leave to apply:";
        cin>>applyLeaveNum;
        if(applyLeaveNum<=3 ){
                casualLeave(currentId,applyLeaveNum);
                staffInfo();
                 //applyLeave();
                 mainMenu();

        }else
        {
            cout<<"Can you apply only maximum three days at one time or casual leave."<<endl;
            applyLeave();
        }

    }
    else if(typeofLeave==2){
        cout<<"Type number of medical leave to apply:";
        cin>>applyLeaveNum;
        if(applyLeaveNum<=30){
            medicalLeave( currentId, applyLeaveNum);
            staffInfo();
            //applyLeave();
            mainMenu();
        }

        else{
            cout<<"Can you apply only maximum 1 month at one time for medical leave."<<endl;
            applyLeave();
        }

        }
        else if(typeofLeave==3){
            login();

        }
        else{
            cout<<"Invalid types of leave!";
            applyLeave();
        }

    }

int Staff::casualLeave(int currentId, int cleave) {

    if((cLeave[currentId]+cleave)<=10) {
        cLeave[currentId]=cLeave[currentId]+cleave;
        cout<<"Successfully apply casual leave:"<< staffName[currentId]<<endl;
        cout<<"Number of Casual leave you applied:"<<cleave<<"days"<<endl;
    }else
    {
        cout<<"Casual Leave limit exceeded"<<endl;
    }
}


int Staff::medicalLeave(int currentId, int mleave) {
    int calSalary= ((staffSalary[currentId]/2)/30)*mleave;
     netSalary[currentId]=staffSalary[currentId]-calSalary;
    if((mLeave[currentId]+mleave)<=365) {
        mLeave[currentId] = mLeave[currentId] + mleave;
        cout << "Successfully apply medical leave:" << staffName[currentId] << endl;
        cout << "Number of medical leave you applied:" << mleave << "days" << endl;

    }
    else{
        cout<<"Medical Leave limit exceeded"<<endl;
    }
}

int Staff::mainMenu() {
    int option=10;
    while(true){
        cout<<"Press 1 to Register:"<<endl;
        cout<<"Press 2 to Login:"<<endl;
        cout<<"Press 3 to Quit."<<endl;
        cin>>option;
        if(option==1){
            sRegister();
        }
        else if(option==2){
           int status=login();
           if(status==100){
               cout<<"Try Again!"<<endl;
           }
           //login();

        }
        else{
            cout<<"bye bye"<<endl;
            return 0;
        }
    }
}

int Staff::staffInfo() {
    /*cout<<"Staff Name"<<"      "<<"Password"<<"       "<< "Number of Leave"<<endl;
    for(int i=0; i<locate; i++){
        cout<<staffName[i]<<"             "<<sPassword[i]<<"              "<<numofLeave[i]<<endl;

    }*/
    cout<<"Staff Name"<<endl;
    for(int i=0; i<=locate; i++){
        cout<<" "<<staffName[i]<<endl;
    }
    cout<<"Password"<<endl;
    for(int i=0;i<=locate; i++){
        cout<<"  "<<sPassword[i]<<endl;
    }
    cout<<"Salary"<<endl;
    for(int i=0;i<locate; i++){
        cout<<"  "<<staffSalary[i]<<endl<<endl;
    }
    cout<<"Number of Casual Leave"<<endl;
    for(int i=0;i<locate; i++){
        cout<<" "<<cLeave[i]<<endl<<endl;
    }
    cout<<"Number of Medical Leave"<<endl;
    for(int i=0;i<locate; i++){
        cout<<" "<<mLeave[i]<<endl<<endl;
    }

    cout<<"Net Salary"<<endl;
    for(int i=0;i<locate; i++){
        cout<<"  "<<netSalary[i]<<endl<<endl;
    }
}

int main(){
    Staff _obj;
    int ex=_obj.mainMenu();
    if(ex==0){
        exit(1);
    }
