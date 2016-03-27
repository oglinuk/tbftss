/*
Copyright (C) 2015-2016 Parallel Realities

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "objectives.h"

void doObjectives(void)
{
	int objectiveFailed;
	int numHiddenObjectives;
	Objective *o;
	
	battle.numObjectivesComplete = battle.numObjectivesTotal = 0;
	objectiveFailed = 0;
	numHiddenObjectives = 0;
	
	for (o = battle.objectiveHead.next ; o != NULL ; o = o->next)
	{
		if (o->active)
		{
			if (!o->isCondition)
			{
				battle.numObjectivesTotal++;
			}
		}
		else
		{
			numHiddenObjectives++;
		}
		
		if (o->currentValue == o->targetValue)
		{
			switch (o->status)
			{
				case OS_COMPLETE:
					battle.numObjectivesComplete++;
					break;
					
				case OS_FAILED:
					objectiveFailed = 1;
					break;
			}
		}
	}
	
	if (battle.status == MS_IN_PROGRESS)
	{
		if (!battle.manualComplete && numHiddenObjectives == 0 && battle.numObjectivesTotal > 0 && battle.numObjectivesComplete == battle.numObjectivesTotal)
		{
			completeMission();
		}
		
		if (objectiveFailed)
		{
			failMission();
		}
	}
}

void updateObjective(char *name, int type)
{
	Objective *o;
	int completed;
	
	completed = battle.numObjectivesComplete;
	
	for (o = battle.objectiveHead.next ; o != NULL ; o = o->next)
	{
		if (o->active && o->status != OS_COMPLETE)
		{
			if (!o->isEliminateAll && !o->isCondition && o->targetType == type && o->currentValue < o->targetValue && strcmp(o->targetName, name) == 0)
			{
				o->currentValue++;
				
				if (!o->hideNumbers)
				{
					if (o->targetValue - o->currentValue <= 10)
					{
						addHudMessage(colors.cyan, "%s - %d / %d", o->description, o->currentValue, o->targetValue);
					}
					else if (o->currentValue % 10 == 0)
					{
						addHudMessage(colors.cyan, "%s - %d / %d", o->description, o->currentValue, o->targetValue);
					}
				}
				
				if (o->currentValue == o->targetValue)
				{
					addHudMessage(colors.green, _("%s - Objective Complete!"), o->description);
					
					runScriptFunction(o->description);
					
					o->status = OS_COMPLETE;
					
					runScriptFunction("OBJECTIVES_COMPLETE %d", ++completed);
				}
			}
			
			if (o->isEliminateAll && o->status != OS_COMPLETE && battle.stats[STAT_ENEMIES_KILLED] == battle.numInitialEnemies)
			{
				addHudMessage(colors.green, _("%s - Objective Complete!"), o->description);
				
				o->currentValue = o->targetValue;
				
				o->status = OS_COMPLETE;
				
				runScriptFunction("OBJECTIVES_COMPLETE %d", ++completed);
			}
		}
	}
	
	if (completed == battle.numObjectivesTotal)
	{
		runScriptFunction("ALL_OBJECTIVES_COMPLETE");
	}
}

void adjustObjectiveTargetValue(char *name, int type, int amount)
{
	Objective *o;
	
	for (o = battle.objectiveHead.next ; o != NULL ; o = o->next)
	{
		if (o->active && !o->isCondition && o->targetType == type && o->currentValue < o->targetValue && strcmp(o->targetName, name) == 0)
		{
			o->targetValue += amount;
			o->currentValue = MIN(o->currentValue, o->targetValue);
			
			if (o->currentValue >= o->targetValue)
			{
				o->status = OS_COMPLETE;
				addHudMessage(colors.green, _("%s - Objective Complete!"), o->description);
			}
		}
	}
}

void updateCondition(char *name, int type)
{
	Objective *o;
	
	for (o = battle.objectiveHead.next ; o != NULL ; o = o->next)
	{
		if (o->active && o->isCondition && o->targetType == type && o->currentValue < o->targetValue && strcmp(o->targetName, name) == 0)
		{
			o->currentValue++;
			
			if (o->currentValue == o->targetValue)
			{
				o->status = OS_FAILED;
				addHudMessage(colors.red, _("%s - Objective Failed!"), o->description);
			}
		}
	}
}

void completeConditions(void)
{
	Objective *o;
	
	for (o = battle.objectiveHead.next ; o != NULL ; o = o->next)
	{
		if (o->isCondition)
		{
			o->status = OS_COMPLETE;
		}
	}
}


void failIncompleteObjectives(void)
{
	Objective *o;
	
	for (o = battle.objectiveHead.next ; o != NULL ; o = o->next)
	{
		if (o->status != OS_COMPLETE)
		{
			o->status = OS_FAILED;
		}
	}
}

void activateObjectives(char *objectives)
{
	char *token;
	Objective *o;
	
	token = strtok(objectives, ";");
	
	while (token)
	{
		for (o = battle.objectiveHead.next ; o != NULL ; o = o->next)
		{
			if (strcmp(token, o->id) == 0)
			{
				addHudMessage(colors.cyan, _("New Objective : %s"), o->description);
				o->active = 1;
				
				if (o->isEliminateAll)
				{
					updateObjective(o->targetName, o->targetType);
				}
			}
		}
		
		token = strtok(NULL, ";");
	}
}

void loadObjectives(cJSON *node)
{
	Objective *o;

	if (node)
	{
		node = node->child;

		while (node)
		{
			o = malloc(sizeof(Objective));
			memset(o, 0, sizeof(Objective));
			battle.objectiveTail->next = o;
			battle.objectiveTail = o;

			STRNCPY(o->id, cJSON_GetObjectItem(node, "description")->valuestring, MAX_DESCRIPTION_LENGTH);
			STRNCPY(o->description, _(cJSON_GetObjectItem(node, "description")->valuestring), MAX_DESCRIPTION_LENGTH);
			STRNCPY(o->targetName, cJSON_GetObjectItem(node, "targetName")->valuestring, MAX_NAME_LENGTH);
			o->targetValue = cJSON_GetObjectItem(node, "targetValue")->valueint;
			o->targetType = lookup(cJSON_GetObjectItem(node, "targetType")->valuestring);
			o->active = getJSONValue(node, "active", 1);
			o->isCondition = getJSONValue(node, "isCondition", 0);
			o->isEliminateAll = getJSONValue(node, "isEliminateAll", 0);
			o->hideNumbers = getJSONValue(node, "hideNumbers", 0);

			if (o->isEliminateAll)
			{
				o->targetValue = 1;
			}

			node = node->next;
		}
	}
}
