function varargout = Trajectory_draw(varargin)
% TRAJECTORY_DRAW MATLAB code for Trajectory_draw.fig
%      TRAJECTORY_DRAW, by itself, creates a new TRAJECTORY_DRAW or raises the existing
%      singleton*.
%
%      H = TRAJECTORY_DRAW returns the handle to a new TRAJECTORY_DRAW or the handle to
%      the existing singleton*.
%
%      TRAJECTORY_DRAW('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in TRAJECTORY_DRAW.M with the given input arguments.
%
%      TRAJECTORY_DRAW('Property','Value',...) creates a new TRAJECTORY_DRAW or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Trajectory_draw_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Trajectory_draw_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Trajectory_draw

% Last Modified by GUIDE v2.5 06-Jun-2021 16:10:49

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Trajectory_draw_OpeningFcn, ...
                   'gui_OutputFcn',  @Trajectory_draw_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Trajectory_draw is made visible.
function Trajectory_draw_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Trajectory_draw (see VARARGIN)

% Choose default command line output for Trajectory_draw
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Trajectory_draw wait for user response (see UIRESUME)
% uiwait(handles.figure1);
set(handles.edit1, 'string','COM1');

% --- Outputs from this function are returned to the command line.
function varargout = Trajectory_draw_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;
global obj;

% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global gParameter
global obj;
gParameter=1;
port_name=get(handles.edit1,'string');
obj = serial(port_name) ;      %creating the object
set(obj,'BaudRate',9600,'DataBits',8,'timeout',10);   %setting baudrate
fopen(obj); %open port
set(obj,'terminator','LF')  %providing the terminator
x=[];y=[];la=[];lo=[];
while gParameter %infinite loop
ip_data = fscanf(obj); %reading port
C = strsplit(ip_data,',');
lat_part=C{3};
lat_dir=C{4};
lat_degrees=str2num(lat_part(1:2));
lat_minutes=str2num(lat_part(3:8));
lat=lat_degrees+(lat_minutes/60);
if(lat_dir=='S')lat=-lat; end
lon_part=C{5};
lon_dir=C{6};
lon_degrees=str2num(lon_part(1:3));
lon_minutes=str2num(lon_part(4:9));
lon=lon_degrees+(lon_minutes/60);
if(lon_dir=='W')lon=-lon; end
[new_x,new_y]=grn2eqa(lat,lon);
x=[x new_x];
y=[y new_y];
la=[la lat];
lo=[lo lon];
plot(handles.axes1,x,y);
wmline(la,lo);
pause(1.5);
if(gParameter==0)
   
end
end

% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global gParameter
gParameter=0;
global obj
 fclose(obj);
    delete(obj);
    clear obj;

function edit1_Callback(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit1 as text
%        str2double(get(hObject,'String')) returns contents of edit1 as a double


% --- Executes during object creation, after setting all properties.
function edit1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end




