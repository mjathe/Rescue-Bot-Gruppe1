# Rettungsroboter - Projekt angewandte Elektrotechnik
Wenn Menschen an gefährlichen Orten verunfallen. müssen diese gerettet werden. Manchmal ist die Situation so gefährlich, dass eine erhöhte Gefahr für den Rettenden nicht ausgeschlossen werden kann. In solchen Situation ist es sinnvoll Rettungsroboter einzusetzen.

Im Rahmen dieses Projekts soll ein Rettungsroboter entwickelt werden, welcher sich autonom in einer festgelegten Umgebung bewegen kann.
## Projektmanagement
[Trello](https://trello.com/b/rEBa2gHf/rescue-bot-group-1)

## Szenario
Das Szenario ist ein Waldbrand. Der Roboter wird an einer bestimmten Stelle ausgesetzt und soll sich autonom zu der zu rettenden Person navigieren. Für die Selbstbehandlung der Person, trägt der Roboter ein Erste-Hilfe-Kit mit sich. Außerdem soll bei der Person ein blaues Rauchsignal gezündet werden, damit ein Rettungsteam den Standort bestimmen kann. Für die Kommunikation zwischen Rettungsteam und der Person besitzt der Roboter eine Gegensprechanlage.

## Requirements
| ID |Description  |
|--|--|
|  FR A|Der Roboter muss autonom fahren können.  |
| FR A.1|Der Roboter muss auf dem Land fahren können.|
|NFR A.1.1 | Der Roboter soll auf Ketten fahren.|
|FR A.2|Der Roboter muss auf dem Wasser fahren können.|
|FR A.2.1|Der Roboter muss schwimmen können.|
|FR A.2.2|Der Roboter muss wasserfest sein.|
|NFR A.2.3|An den Ketten befinden sich Paddelbleche für die Bewegung im Wasser.|
|FR A.3|Der Roboter muss Hindernissen ausweichen können.|
|FR A.3.1|Der Roboter muss Hindernisse erkennen.|
|FR B|Der Roboter muss einen Erste-Hilfe-Kasten tragen können.|
|FR C|Der Roboter muss Schallsignale erkennen und differenzieren können.|
|FR C.1|Der Roboter muss Schallsiganle in der Ebene aus allen 4 Richtungen erkennen.|
|FR D|Der Roboter muss das zu retten Objekt identifizieren können.|
|FR D.1|Der Roboter muss die Temperatur des Objekts bestimmen können.|
|FR D.2|Die Temperatur soll über eine Wärmebildkamera bestimmt werden.|
|FR E|Der Roboter soll eine Gegensprechanlage besitzen.|
|FR F|Der Roboter muss sich bei größerer Beladung für den Landweg entscheiden.|




## Kontextdiagramm

![Kontextdiagramm](/REVISION/diagrams/contex_diagram.png)

## Use Case Diagram

![Use Case Diagram](/REVISION/diagrams/Use_Case.png)

