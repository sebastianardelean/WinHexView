                    Template version 0.1 released in "30-01-2016" author "23ars"

## WinHexView

| General Test Report for **WinHexView**-1.0  |                        |              |                 |
| ------------------------- | ---------------------- | ---------------------- | ----------------------------- |
| **No of tests performed** | **No of failed tests** | **No of passed tests** | **No of not performed tests** |
|        8                  |        0               |      8                 |        0                      |


---


| SW Name Test Report        |                |               |                     |                   |                               |                 |
|----------------------------|----------------|---------------|---------------------| ----------------- | ----------------------------- | --------------- |
| **Tester:**                | 23ars                                                |
| **Software Version:**      | 1.0                                                  |
|                                                                                   |
| **Test ID** | **Test Priority** | **Test Name**		   | **Precondition**        | **Test Steps**                             | **Expected Results**          | **Test Status** |
|    1        |  Recommended      | Read File              |    None                 | Run software and check if file is read     | File is read                  |   PASS          |
|    3        |  Recommended      |	Default Format		   |    None                 | App should print content in default format | Format is printed             |   PASS          |
|    4        |  Recommended      |	/A format   		   |    None                 | <offset> <content> <content> <characters>  | Format is printed             |   PASS          |
|    8        |  Recommended      | /O format              |    None                 | <offset> <octal content>					  | Format is printed             |   PASS          |
|    9        |  Recommended      | /C format              |    None                 | <offset> <char content>					  | Format is printed             |   PASS          |
|    10       |  Recommended      | /D format              |    None                 | <offset> <decimal content>	     		  | Format is printed             |   PASS          |
|    11       |  Recommended      | One format option      |    None                 | Run app with 2 format options			  | First format is used          |   PASS          |
|    14       |  Recommended      | FileOutput             |    None                 | Run app with file output option 			  | Output is redirected to file  |   PASS          |



---

##Notes

**Test ID** is id of specification that will be tested or the issue's id in which a new feature was added to software.

**Test Priority** will have one of the following values:
* *Critical*
* *Recommended*
* *Important*

**Test Name** is the name of the feature that is tested or name of the issue in which a new feature was added.

**Test Status** will have one of the following values:
* *PASS*
* *FAIL*
* *NOT TESTED*  
