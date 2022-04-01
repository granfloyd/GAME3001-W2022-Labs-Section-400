#include "RangedCombatCondition.h"

RangedCombatCondition::RangedCombatCondition(const bool within_combat_range)
{
	m_name = "Ranged Combat Condition";
	setWithinCombatRange(within_combat_range);
}

RangedCombatCondition::~RangedCombatCondition()
= default;

void RangedCombatCondition::setWithinCombatRange(const bool state)
{
	m_within_combat_range = state;
}

bool RangedCombatCondition::Condition()
{
	return m_within_combat_range;
}

