// -*- coding: latin-1 -*-

// This file is part of RefactorErl.
//
// RefactorErl is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// RefactorErl is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with RefactorErl.  If not, see <http://plc.inf.elte.hu/erlang/>.
//
// The Original Code is RefactorErl.
//
// The Initial Developer of the Original Code is Eötvös Loránd University.
// Portions created  by Eötvös Loránd University and ELTE-Soft Ltd.
// are Copyright 2007-2013 Eötvös Loránd University, ELTE-Soft Ltd.
// and Ericsson Hungary. All Rights Reserved.

//Author: Mátyás Kuti

#ifndef INVESTIGATIONEDGEITEM_H
#define INVESTIGATIONEDGEITEM_H

#include <QGraphicsItem>
#include "investigationproxyitem.h"

class InvestigationProxyItem;

//This class is used to draw an edge between to InvestigationProxyItems
// on a QGraphicsView
class InvestigationEdgeItem : public QGraphicsItem
{
    private:
        InvestigationProxyItem *from_, *to_;
        QPointF from_point_;
        QPointF to_point_;
        qreal arrow_size_;

    protected:
        QRectF boundingRect() const override;
        void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget) override;

    public:
        InvestigationEdgeItem(InvestigationProxyItem *from,
                              InvestigationProxyItem *to);
        InvestigationProxyItem *From() const;
        InvestigationProxyItem *To() const;
        //If the starting and ending items' position is changed
        // this function recalculates the starting and point on the
        // QGraphicsView
        void Adjust();


};

#endif // INVESTIGATIONEDGEITEM_H
