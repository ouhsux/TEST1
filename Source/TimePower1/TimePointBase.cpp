// Fill out your copyright notice in the Description page of Project Settings.


#include "TimePointBase.h"

//UTimepointBase* UTimePointBase::Interpolate(const UTimepointBase* other, float distance) const
//{
//	return DuplicateObject(this, nullptr);
//}

UTimePointBase* UTimePointBase::Interpolate_Implementation(const UTimePointBase* other, float distance) const
{
	return DuplicateObject(this,nullptr);
}
