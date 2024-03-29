## Begin

Reset and initialize sensor to default state.

```Arduino
bool begin()
```
### Return

- A **boolean** result of initialization. (`true` / `false`)
<br /><br /><br />
***
<br />

## Get Gyro

Get **gyro** data from the given axis.

```Arduino
int getGyro(AxisType axis)
```

### Parameters

- `AxisType` is a string with the axis of sensor. (Options: `x` / `y` / `z`)

### Return

- An **int** number from `-250` through `250`. (unit: degree per second)
<br /><br /><br />
***
<br />

## Get Accel

Get **accel** data from the given axis.

```Arduino
int getAccel(AxisType axis)
```

### Parameters

- `axis` is a string with the axis of sensor. (Options: `x` / `y` / `z`)

### Return

- An **int** number from `-32767` through `32767`. (unit: mm/s^2)
<br /><br /><br />
***
<br />

## Get Roll

Get **Roll** data.

```Arduino
int getRoll()
```
### Return

- An **int** number from `-180` through `180`. (unit: degree)
<br /><br /><br />
***
<br />


## Get Pitch

Get **pitch** data.

```Arduino
int getPitch()
```

### Return

- An **int** number from `-90` through `90`. (unit: degree)
<br /><br /><br />
***
<br />


## Get Yaw

Get **yaw** data.

```Arduino
int getYaw()
```

### Return

- An **int** number from `-180` through `180`. (unit: degree)
<br />